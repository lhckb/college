# sort integer array from smallest to largest
def findSmallest(arr):
    smallest = arr[0]
    index_smallest = 0
    for i in range(1, len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            index_smallest = i

    return index_smallest

def selectSort(arr):
    new_array = []
    for i in range(len(arr)):
        smallest = findSmallest(arr)
        new_array.append(arr.pop(smallest))

    return new_array

array = [1, 4, 3, 2, 6, 9, 5, 82]

print(selectSort(array))
