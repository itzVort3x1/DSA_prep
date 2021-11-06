# ----------------------------------
# Sum of N natural numbers
# ----------------------------------
userInput = int(input("Please enter a number: "))
total = 0
for val in range(1, userInput + 1):
    total = total + val

print("The sum of Natural Numbers from 1 to {0} = {1}".format(userInput, total))


# ----------------------------------
# Factorial of a number
# ----------------------------------
userInput = int(input("Please enter a number: "))
def factorial(n):
    fact = 1
    for num in range(2, n + 1):
        fact = fact * num
    return fact
total = factorial(userInput)
print("The factorial of {0} is {1}".format(userInput, total))

