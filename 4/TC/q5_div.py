def divide(x, y):
    count = 0
    while x >= y:  # while x < y == 0
        # print(x, y)
        x = x - y
        count += 1
    return count

# print(divide(10, 2))

def resto(x, y):
    while x >= y:
        x = x - y
    return x

print(resto(5, 0))