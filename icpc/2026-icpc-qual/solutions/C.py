"""ICPC NERC Kyrgyzstan Qualification 2026 · C · Сизифов труд."""

import sys


def solve() -> None:
    data = list(map(int, sys.stdin.buffer.read().split()))
    answers = []
    for a, b in zip(data[1::2], data[2::2]):
        # f(k) = k·A − B·k(k−1)/2. Its increments are A − k·B,
        # so the maximum is attained at k = ceil(A / B).
        k = (a + b - 1) // b
        answers.append(str(k * a - b * k * (k - 1) // 2))
    print('\n'.join(answers))


if __name__ == '__main__':
    solve()
