with open("input.txt") as file:
    part1 = 0
    part2 = 0
    for x in file:
        line = x.split()
        numbers = line[0].split('-')
        print(line)
        print(f"{numbers[0]}, {line[2].count(line[1][0])}, {numbers[1]}")
        if int(numbers[0]) <= line[2].count(line[1][0]) <= int(numbers[1]):
            part1 += 1
        counter = 0
        counter += 1 if line[2][int(numbers[0])-1] == line[1][0] else 0
        counter += 1 if line[2][int(numbers[1]) - 1] == line[1][0] else 0
        if 0 < counter < 2:
            part2 += 1
print(part1)
print(part2)