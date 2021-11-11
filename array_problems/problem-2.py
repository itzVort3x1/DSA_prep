#---------------------------
# Problem 1: Find the maximum and minimum element in an array
#---------------------------


arr = [12, 20, 9, 8, 52, 100, 6]
max = 0
min = arr[0]
for i in range(len(arr)):
    if max < arr[i]:
        max = arr[i]

    if min > arr[i]:
        min = arr[i]

print("max: ", max)
print("min: ", min)