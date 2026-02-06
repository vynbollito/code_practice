'''
While 'game'
guess a number, 3 tries
0-9
'''
import random

current = random.randint(1,9)
guess = 0
print("\n\t\t\tGuess the number (1,9). Your have 3 opportunities")
while guess < 3:
    print('------------------------------------------------------------------------------------')
    print("\tTries: "+str(guess))
    num = int(input('Guess: '))

    if num < 1 or num > 9:
        print('Remember, the number is between 1 and 9')
        guess = guess + 1
    elif current == num:
        print('Correct! You guessed the number\n')
        # only to finish the loop
        guess = 5
    else:
        print('\t\tNop :(')
        guess = guess + 1
else:
    print('\n------------------------------------------------------------------------------------')
    print(" <Game over. But don't worry, you can try again>\n")

'''
Try the else in the while loop, works the same as this: 
if guess == 3:
    print('------------------------------------------------------------------------------------')
    print("<The game is over. But don't worry, you can try it again>")
'''

'''
FOR loops
'''
# the index takes the value of each element of the collection, list, array
for index in 'Python':
    print(index)

# same for the list
for index in ['Python', 'C', 'Java', 'SQL']:
    print(index)

for index in [1,2,3,4,5,6,7,8,9,10]:
    print(index)
# range(5), will display from 0 to 5 
# the last num is not included (i=25; i<45;i++)
for index in range(25,45):
    print(index)
# range(start, end, jump) (i=50; i<10; i+=5)
for index in range(50,100,5):
    print(index)
# example
prices = [10, 20, 30]
total = 0
for price in prices:
    total += price
print(f'The total price is: {total}')

# cute exercises
list = [5, 2, 5, 2, 2]

for i in list:
    output = ''
    for j in range(i):
        output += 'x'
    print(output)

