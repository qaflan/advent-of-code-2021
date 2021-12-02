import sys


def read_input(input_file):
    with open(input_file, "r") as f:
        lines = [float(line) for line in f.readlines()]
    return lines


def count_increases(lines):
    increases = [1 if b - a > 0 else 0 for a, b in zip(lines, lines[1:])]
    count = sum(increases)
    return count


if __name__ == "__main__":
    input_file = sys.argv[1] if len(sys.argv) > 1 else "input.txt"
    lines = read_input(input_file)
    count_single_lines = count_increases(lines)
    print(f"part 1: {count_single_lines}")

    zipped_lines = zip(lines, lines[1:], lines[2:])
    summed = [sum(x) for x in zipped_lines]
    count_window = count_increases(summed)
    print(f"part 2: {count_window}")
