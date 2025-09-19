# Quick Sort Implementation in Python

def quick_sort(arr, si, ei):
    if si >= ei:
        return
    
    # Partition using last element as pivot
    pivot_index = partition_end(arr, si, ei)
    quick_sort(arr, si, pivot_index - 1)   # Left side
    quick_sort(arr, pivot_index + 1, ei)   # Right side


# Partition when pivot is the first element
def partition_first(arr, si, ei):
    pivot = arr[si]
    i = si
    for j in range(si + 1, ei + 1):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i], arr[si] = arr[si], arr[i]
    return i


# Partition when pivot is the middle element (method 1)
def partition_mid(arr, si, ei):
    mid = (si + ei) // 2
    pivot = arr[mid]
    arr[mid], arr[ei] = arr[ei], arr[mid]   # Move pivot to end
    i = si - 1
    for j in range(si, ei):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    i += 1
    arr[i], arr[ei] = arr[ei], arr[i]
    return i


# Partition when pivot is the middle element (method 2, Hoare scheme)
def partition_mid2(arr, si, ei):
    pivot = arr[(si + ei) // 2]
    i, j = si, ei
    while i <= j:
        while arr[i] < pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
    return i


# Partition when pivot is the last element
def partition_end(arr, si, ei):
    pivot = arr[ei]
    i = si - 1
    for j in range(si, ei):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    i += 1
    arr[i], arr[ei] = arr[ei], arr[i]
    return i


# Function to print array
def print_array(arr):
    for num in arr:
        print(num, end=" ")
    print()


# Main Program
if __name__ == "__main__":
    arr = [6, 3, 1, 9, 7]  # Same input as previous merge sort example
    print("Original Array:")
    print_array(arr)

    quick_sort(arr, 0, len(arr) - 1)

    print("Sorted Array:")
    print_array(arr)
