#!/usr/bin/env python3
"""Инструменты для олимпиадных задач.

1) Прогон примеров из файлов (tests/A/1.in + 1.out, 2.in + 2.out ...):
   python3 tools/olymp.py samples A.cpp tests/A

2) Стресс-тест: решение против перебора на случайных тестах:
   python3 tools/olymp.py stress A.cpp brute_A.py gen_A.py [число_тестов]

Флаг --float включает сравнение чисел с точностью 1e-6.
Поддерживаются файлы .cpp и .py. C++ собирается с санитайзерами
(ловят выход за границы массива, переполнение int, неинициализированные данные).
"""
import os
import shutil
import subprocess
import sys
import tempfile
import time

TIME_LIMIT = 5      # секунд на одно решение
BRUTE_LIMIT = 20    # секунд на перебор
GEN_LIMIT = 10


def prepare(path, workdir, sanitize):
    ext = os.path.splitext(path)[1]
    if ext == ".cpp":
        out = os.path.join(workdir, os.path.basename(path) + ".bin")
        flags = ["-std=c++17", "-O1", "-g", "-Wall", "-Wextra", "-Wno-unused-result"]
        if sanitize:
            flags += ["-fsanitize=address,undefined", "-fno-sanitize-recover=undefined"]
        r = subprocess.run(["g++"] + flags + [path, "-o", out], capture_output=True, text=True)
        if r.returncode != 0:
            print("Ошибка компиляции:\n" + r.stderr)
            sys.exit(1)
        if r.stderr.strip():
            print("Предупреждения компилятора (посмотри их, часто это и есть баг):\n" + r.stderr)
        return [out]
    if ext == ".py":
        return [sys.executable, path]
    print("Неизвестный тип файла:", path)
    sys.exit(1)


def run(cmd, inp, limit, args=()):
    start = time.time()
    try:
        r = subprocess.run(cmd + [str(a) for a in args], input=inp,
                           capture_output=True, text=True, timeout=limit)
    except subprocess.TimeoutExpired:
        return None, limit
    return r, time.time() - start


def same(a, b, use_float):
    ta, tb = a.split(), b.split()
    if len(ta) != len(tb):
        return False
    for x, y in zip(ta, tb):
        if x == y:
            continue
        if use_float:
            try:
                fx, fy = float(x), float(y)
                if abs(fx - fy) <= 1e-6 * max(1.0, abs(fy)):
                    continue
            except ValueError:
                pass
        return False
    return True


def show(text, limit=600):
    text = text.strip()
    return text if len(text) <= limit else text[:limit] + "\n... (обрезано)"


def cmd_samples(args, use_float):
    if len(args) < 2:
        print(__doc__)
        return 1
    sol_path, folder = args[0], args[1]
    work = tempfile.mkdtemp()
    sol = prepare(sol_path, work, True)
    names = sorted(f[:-3] for f in os.listdir(folder) if f.endswith(".in"))
    if not names:
        print("В папке нет файлов .in")
        return 1
    bad = 0
    for name in names:
        inp = open(os.path.join(folder, name + ".in")).read()
        out_path = os.path.join(folder, name + ".out")
        r, t = run(sol, inp, TIME_LIMIT)
        if r is None:
            print(f"[{name}] TIMEOUT (> {TIME_LIMIT} c)")
            bad += 1
            continue
        if r.returncode != 0:
            print(f"[{name}] RUNTIME ERROR, код {r.returncode}\n{show(r.stderr)}")
            bad += 1
            continue
        if not os.path.exists(out_path):
            print(f"[{name}] нет эталона {name}.out, ответ:\n{show(r.stdout)}")
            continue
        exp = open(out_path).read()
        if same(r.stdout, exp, use_float):
            print(f"[{name}] OK ({t:.2f} c)")
        else:
            bad += 1
            print(f"[{name}] WRONG ANSWER\nвход:\n{show(inp)}\nожидалось:\n{show(exp)}\nполучено:\n{show(r.stdout)}")
    print("\nВсе примеры прошли" if bad == 0 else f"\nПровалено: {bad}")
    return 0 if bad == 0 else 1


def cmd_stress(args, use_float):
    if len(args) < 3:
        print(__doc__)
        return 1
    sol_p, brute_p, gen_p = args[:3]
    n = int(args[3]) if len(args) > 3 else 500
    work = tempfile.mkdtemp()
    sol = prepare(sol_p, work, True)
    brute = prepare(brute_p, work, False)
    gen = prepare(gen_p, work, False)
    worst = 0.0

    def fail(seed, inp, why, exp="", got=""):
        with open("fail_input.txt", "w") as f:
            f.write(inp)
        print(f"\nПРОВАЛ на seed={seed}: {why}")
        print("Вход сохранён в fail_input.txt (запусти: решение < fail_input.txt)")
        print("вход:\n" + show(inp))
        if exp or got:
            print("перебор:\n" + show(exp))
            print("решение:\n" + show(got))
        return 1

    for seed in range(1, n + 1):
        g, _ = run(gen, "", GEN_LIMIT, [seed])
        if g is None or g.returncode != 0:
            print("Генератор упал или завис, seed =", seed, g.stderr if g else "")
            return 1
        inp = g.stdout
        b, _ = run(brute, inp, BRUTE_LIMIT)
        if b is None or b.returncode != 0:
            return fail(seed, inp, "перебор упал или завис (проверь перебор и генератор)",
                        got=b.stderr if b else "")
        s, t = run(sol, inp, TIME_LIMIT)
        if s is None:
            return fail(seed, inp, f"решение не уложилось в {TIME_LIMIT} c (TLE или бесконечный цикл)")
        worst = max(worst, t)
        if s.returncode != 0:
            return fail(seed, inp, "решение упало (runtime error / санитайзер)", got=s.stderr)
        if not same(s.stdout, b.stdout, use_float):
            return fail(seed, inp, "ответы разные (WA)", b.stdout, s.stdout)
        if seed % 100 == 0:
            print(f"... {seed}/{n} тестов ок")
    print(f"\nВсе {n} тестов прошли. Самое долгое решение: {worst:.2f} c")
    print("Теперь прогони максимальный тест отдельно, стресс проверяет только правильность.")
    return 0


def main():
    flags = [a for a in sys.argv[1:] if a.startswith("--")]
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    use_float = "--float" in flags
    if not args:
        print(__doc__)
        return 1
    mode, rest = args[0], args[1:]
    if mode == "samples":
        return cmd_samples(rest, use_float)
    if mode == "stress":
        return cmd_stress(rest, use_float)
    print(__doc__)
    return 1


if __name__ == "__main__":
    sys.exit(main())
