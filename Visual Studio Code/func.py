def intersection(a: list, b: list):
    return [x for x in a if x in b]


a = [1, 3, 5, 6, 7, 8]
b = [12, 8, 42, 14, 3, 6]
# [3, 6, 8]

c = intersection(a, b)

print(c)

