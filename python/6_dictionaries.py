'''
Dictionaries
'''
# each key should be unique
customer = {'name': 'Kaka', 'age': 35, 'is_verified': True}
# case sensitive
print(customer['name'])
# another way for accessing
print(customer.get('name'))
# if the key does not exist it can be displayed
# It is not saved into customer obj, only displayed
print(customer.get('birthday','19 11 1993'))
print(customer)

## Adding
# update a value
customer['name'] = 'Ronaldo'
# add a new key
customer['birthday'] = '22 Sep 1976'
print(customer)

'''
Dictionary example
'''
# dictionary
numbers = {'0': 'Zero', '1': 'One', '2': 'Two', '3': 'Three', 
'4': 'Four', '5': 'Five', '6': 'Six', '7': 'Seven', '8': 'Eight', '9':'Nine'}
# ask for nums
phone = input('Phone: ')
# compare it keys within dictionary 
full_num = ''
for replace in phone:
    full_num += numbers.get(replace, '?') + ' '
# display
print(full_num)

'''
Emoji convertor exercise
'''
emoji_dictionary = {
    ":)": "😊",
    ":(": "😞",
    ":S'": "😖",
    ":'(": "😭",
    ":'D": "🤣"
}
msg = input('> ').split(' ')
out = ''
for word in msg:
    # if the emoji is not found use the word written
    out += ' ' + emoji_dictionary.get(word, word)
print(out)
