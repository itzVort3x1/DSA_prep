# ----------------------------------
# Linear search to find if the element is present in the list.
# ----------------------------------
def linearsearch(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

arr = ['t','u','t','o','r','i','a','l']
x = 'l'
print("element found at index " + str(linearsearch(arr,x)))

# ----------------------------------
# Binary search to find if the element is present in the list.
# ----------------------------------
def binary_search(arr, low, high, x):
    if high >= low:
        # For division we are using `//` as in python 3.x this returns an integer whereas
        # `/` this returns an float in python 3.x
        mid = (high+low)//2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return binary_search(arr, low, mid-1, x)
        else:
            return binary_search(arr, mid+1, high, x)
    else:
        return -1

arr = [ 2, 3, 4, 10, 40 ]
x = 2
result = binary_search(arr, 0, len(arr)-1, x)
if result != -1:
    print("Element", x , "is present at index", str(result))
else:
    print("Element is not present in the array")