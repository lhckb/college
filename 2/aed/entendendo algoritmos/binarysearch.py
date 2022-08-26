def binarySearch(list, item):
    bottom = 0
    top = len(list) - 1

    while bottom <= top:
        guess = (top + bottom) // 2

        if list[guess] == item:
            return {'item' : item, 'position' : guess}

        elif list[guess] < item:
            bottom = guess + 1

        elif list[guess] > item:
            top = guess - 1

    return None

items = [1, 2, 3, 5, 6, 7, 9, 44, 65]

if __name__ == '__main__':
    print(f'{binarySearch(items, 44)}')
    print(f'{binarySearch(items, 10)}')