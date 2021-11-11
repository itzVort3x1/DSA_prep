#---------------------------
# Problem 3: Find the kth max and min element of an array
#---------------------------

N = 6
arr = [7,10,4,3,20,15]
k = 3 # here k is the key.

for i in range(len(arr)):
    for j in range(i+1, len(arr)):
        if arr[i] > arr[j]:
            arr[i], arr[j] = arr[j], arr[i]

print(arr)
print("Kth max is: ", arr[-k])
print("kth min is: ", arr[k-1])
