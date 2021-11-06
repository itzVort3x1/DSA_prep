# ----------------------------------
# Sum of N natural numbers
# ----------------------------------
userInput = int(input("Please enter a number: "))
total = 0
for val in range(1, userInput + 1):
    total = total + val

print("The sum of Natural Numbers from 1 to {0} = {1}".format(userInput, total))


# ----------------------------------
# Factorial of a number Iteratinve Method
# ----------------------------------
userInput = int(input("Please enter a number: "))
def factorial(n):
    fact = 1
    for num in range(2, n + 1):
        fact = fact * num
    return fact
total = factorial(userInput)
print("The factorial of {0} is {1}".format(userInput, total))

# ----------------------------------
# Factorial of a number Recursive Method
# ----------------------------------
userInput = int(input("Please enter a number: "))
def factorial(n):
    if n==1 or n==0:
        return 1
    else:
        return n * factorial(n-1);

print("The factorial of {0} is {1}".format(userInput, factorial(userInput)))

# ----------------------------------
# Fibonacci of a number Iterative Method
# ----------------------------------
userInput = int(input("Please enter a number: "))
def fib(n):
    a = 0
    b = 1
    if n == 1:
        print(a)
    else:
        print(a)
        print(b)
        for i in range(2, n):
            c = a + b
            a = b
            b = c
            print(c)
fib(userInput)

# ----------------------------------
# Fibonacci of a number Recursive Method
# ----------------------------------
userInput = int(input("Please enter a number: "))
def fib(n):
    if(n <= 1):
        return n
    else:
        return (fib(n-1) + fib(n-2))

for i in range(userInput):
    print(fib(i))

# ----------------------------------
# To print all prime numbers between N and M
# ----------------------------------
N = int(input("Please enter a start value: "))
M = int(input("Please enter a end value: "))

for i in range(N, M+1):
    if i > 1:
        for j in range(2, i):
            if (i % j) == 0:
                break
        else:
            print(i)

# ----------------------------------
# To find the largest among three numbers, where input is given by the user.
# ----------------------------------
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))
num3 = float(input("Enter third number: "))
 
if (num1 > num2) and (num1 > num3):
   largest = num1
elif (num2 > num1) and (num2 > num3):
   largest = num2
else:
   largest = num3
 
print("The largest number is",largest)

# ----------------------------------
# To find the largest among three numbers, where input is given by the user.
# ----------------------------------
num1 = int(input("Enter the first GCD number: "))
num2 = int(input("Enter the second GCD Number: "))

def gcd(a, b):
    if (a == 0):
        return b
    
    if (b == 0):
        return a
    
    if (a == b):
        return a
  
    if (a > b):
        return gcd(a-b, b)
    return gcd(a, b-a)
  
if(gcd(num1, num2)):
    print('GCD of', num1, 'and', num2, 'is', gcd(num1, num2))
else:
    print('not found')
