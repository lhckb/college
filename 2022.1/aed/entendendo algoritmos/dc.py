# sum every element in an array using recursion
def sumArray(array):
    if array == []:
        return 0

    return array[0] + sumArray(array[1:])

def countItems(array):
    if array == []:
        return 0

    return 1 + countItems(array[1:])


test_array = [1, 2, 3, 4, 5] 

# answer should be 15
print(f'sum is {sumArray(test_array)}')

# answer should be 5
print(f'number of items is {countItems(test_array)}')