import collections
import sys


def visible_books(books):
    visible = [False] * len(books)
    tallest = -1
    for i, height in enumerate(books):
        if height > tallest:
            visible[i] = True
            tallest = height
    tallest = -1
    for i in range(len(books) - 1, -1, -1):
        if books[i] > tallest:
            visible[i] = True
            tallest = books[i]
    return sum(visible)


def main():
    data = list(map(int, open(sys.argv[1]).read().split()))
    output = list(map(int, sys.stdin.read().split()))
    test_count, position, out_position = data[0], 1, 0

    for _ in range(test_count):
        n = data[position]
        position += 1
        original = data[position:position + n]
        position += n
        if out_position >= len(output):
            return 1
        claimed = output[out_position]
        out_position += 1
        arrangement = output[out_position:out_position + n]
        out_position += n

        expected = sum(min(count, 2) for count in collections.Counter(original).values())
        if (len(arrangement) != n or collections.Counter(arrangement) != collections.Counter(original) or
                claimed != expected or visible_books(arrangement) != expected):
            return 1

    return int(out_position != len(output))


if __name__ == '__main__':
    raise SystemExit(main())
