counter = 100       # An integer assignment
miles = 1000.0      # A floating point
name = "John"       # A string

# multiple assignment
a = b = c = 1
x,y,z = 1,2,"john"

#standard Data types on python:
# 1) Numbers
# 2) String
# 3) List
# 4) Tuple
# 5) Dictionary

# python numbers
var1 = 1
var2 = 10
del var1

#python strings
str = 'Hello World!'
print (str)          # Prints complete string
print (str[0])       # Prints first character of the string
print (str[2:5])     # Prints characters starting from 3rd to 5th
print (str[2:])      # Prints string starting from 3rd character
print (str * 2)      # Prints string two times
print (str + "TEST") # Prints concatenated string

# python lists
list = [ 'abcd', 786 , 2.23, 'john', 70.2 ]
tinylist = [123, 'john']

print (list)            # Prints complete list
print (list[0])         # Prints first element of the list
print (list[1:3])       # Prints elements starting from 2nd till 3rd 
print (list[2:])        # Prints elements starting from 3rd element
print (tinylist * 2)    # Prints list two times
print (list + tinylist) # Prints concatenated lists

# python tuples
tuple = ( 'abcd', 786 , 2.23, 'john', 70.2  )
tinytuple = (123, 'john')

print (tuple)               # Prints the complete tuple
print (tuple[0])            # Prints first element of the tuple
print (tuple[1:3])          # Prints elements of the tuple starting from 2nd till 3rd 
print (tuple[2:])           # Prints elements of the tuple starting from 3rd element
print (tinytuple * 2)       # Prints the contents of the tuple twice
print (tuple + tinytuple)   # Prints concatenated tuples

# python dictionary
dict = {}
dict['one'] = "This is one"
dict[2]     = "This is two"

tinydict = {'name': 'john','code':6734, 'dept': 'sales'}


print (dict['one'])       # Prints value for 'one' key
print (dict[2])           # Prints value for 2 key
print (tinydict)          # Prints complete dictionary
print (tinydict.keys())   # Prints all the keys
print (tinydict.values()) # Prints all the values

# lists
list = [1,2,3,4,5,6,7]
print(list)

list1 = [1,2,3,4,5,6,7, 'hi', 'hello']
print(list1)

list1.append('new')
print(list1)

# dictonaries
d1={'a':1, 'b':2, 'c':3}
print(d1)

# string declaration
a = 'Hello'
print(a)

# string traversing
b = "Hello, World!"
print(b[1])

# string slicing
c = "Hello, World!"
print(c[2:5])

# string concatenating
d = "Hello"
e = "World"
f = d + e
print(f)

# string sorting
g = ("b", "g", "a", "d", "f", "c", "h", "e")
print(sorted(g))

# exponent in python
print(2**3)

# single if statement
var = 100
if ( var == 100 ) : print ("Value of expression is 100")
print ("Good bye!")

#Number type conversion 
# 1) int(x)
# 2) float(x)
# 3) long(x)
# 4) complex(x)
# 5) complex(x,y)