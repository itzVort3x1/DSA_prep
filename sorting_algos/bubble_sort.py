def bubble_sort(arr):
    for i in range(0, len(arr)-1):
        for j in range(len(arr)-1):
            if(arr[j] > arr[j+1]):
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
    return arr

list = [15, 43, 38, 64, 71, 82]  
print("The unsorted list is: ", list)  
print("The sorted list is: ", bubble_sort(list))