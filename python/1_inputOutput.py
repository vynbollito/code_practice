'''
every single input is treated as a string
'''
name = input('\nWhat is your name: ')
color = input('What is your fav color: ')
birth_year = input('What is your birth year: ')
age = 2019 - int(birth_year)
print('\nHi! '+name+ ' that likes color '+color+', and you has '+str(age)+' years old.')

'''
single and double quotes
'''
text = "Don't try the sigle quote with this kind of subtraction"
print("\n"+text)

'''
text index
'''
text = "Total"
print("\nOriginal word: "+text)
print("text[-2]: "+text[-2]) # This starts from last letter of the string
print("text[0:3]: "+text[0:3]) # This show the first letter to the second one
print("text[0:]: "+text[0:]) # This show from the first letter to the last one
print("text[:3]: "+text[:3]) # This show from the first letter to the character before indicated
print("text[:]: "+text[:]) # Will return all the characters in the string
print("text[1:-1]: "+text[1:-1]) # this will show: ennife
'''
For more complicated text use the formater
'''
# For more complicated text use the formater
first = 'Oi'
last = 'Bolli'
message = first + ' ['+last+'] is a coder'
# insted of the prev use this:
msg = f'{first} [{last}] is a coder'
print(message)
print(msg)

'''
String functions
'''
txt = 'This is supposed to be a long text and a be word for testing too. To be or not to be'
print(len(txt)) # general purpose function, it can be used with others like lists,...

# this method creates a new one and displays it
print(txt.upper()) # method for string type
print(txt.lower())

# find a character or sequence of characters in a string
# the method is case sensitive, if not found -1
# with words displays the index where the word starts
print(txt.find('p')) # return the index of strings

# creates a new string and displays it. word/letter, new, number of occurances to convert
print(txt.replace('be','BE_BE',3))

# valid if a word/letter extist in string
print('word' in txt)
print('Word' in txt) # remember: case sensitive

