# quicksort implementation
def qsort(array):
    if len(array) < 2:
        return array
    else:
        pivot_index = len(array) // 2
        pivot = array[pivot_index]
        smallers = [i for i in array if i < pivot and array.index(i) != pivot_index]
        greaters = [i for i in array if i > pivot and array.index(i) != pivot_index]

        return qsort(smallers) + [pivot] + qsort(greaters)


test_array = [3, 2, 5, 4, 8, 7]

print(f'sorted: {qsort(test_array)}')