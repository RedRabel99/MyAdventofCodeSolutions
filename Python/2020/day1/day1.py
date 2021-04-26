from functools import reduce
from itertools import combinations


def fun(n):
    for x in combinations([int(x) for x in open("input.txt")], n):
        if sum(x) == 2020:
            return reduce(lambda a, b: a * b, x)


# print(fun(2))
# print(fun(3))


def one_line(n):
    return [reduce(lambda a, b: a * b, x) for x in combinations([int(x) for x in open("input.txt")], n) if sum(x) == 2020]


print(*one_line(2))
print(*one_line(3))
