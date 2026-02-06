'''
Simple if
'''
is_hot = False
is_cold = True
# if looks for True value
if is_hot:
    print("It's a hot day")
    print("Print plenty of water")
elif is_cold:
    print("It's a cold day")
    print("Wear warm cloths")
else:
    print("It's a lovely day")
print('Enjoy your day')

'''
Using logical operators
'''
has_high_income = True
has_good_credit = False
has_criminal_record = True

# AND condition
if has_high_income and has_good_credit:
    print('Eligible for loan')
else:
    print('It cannot be applied for a loan')

# OR condition
if has_high_income or has_good_credit:
    print('Eligible for loan')
else:
    print('It cannot be applied for a loan')

# NOT condition
if has_high_income and not has_criminal_record:
    print('Eligible for loan without criminal record')
else:
    print('It cannot be applied for a loan, person has criminal record')

'''
Comparison operators
'''
temperature = 20

if temperature >= 30:
    print("It's hot")
elif temperature < 30 and temperature > 11:
    print("It's a nice day")
else:
    print("It's freezing out there. Remembe to take you coat with you")

# example with len method
name = 'cghvb'

if len(name) <= 3:
    print('Your name must be greatter than 3 letters')
elif len(name) > 10:
    print('Wooow! That a long name. Please, try with a sorter one')
else:
    print('Your name seems nice!')

'''
Resume exercise
get value of weight
ask for type: lbs | kgs . No case sensitive
convert it
display
'''
v = input('\nEnter your weight: ')
type = input('(L)Lbs or (K)kgs: ')
# Remember: inputs are taken as strings!
value = int(v)

if value <= 0:
    print('Your weight must be greater than 0. Try again')
else:
    # another way to do the validation can be
    # type.upper() == L or lower() can also work
    if type == 'l' or type == 'L':
        value = value *  0.45
        print(f'You weight in kgs is: { value}')
    elif type == 'k' or type == 'k':
        value = value /  0.45
        print(f'You weight in kgs is: { value}')
    else:
        print("Please, enter 'l'for lbs or 'k' for kilograms in order to convert your weight")

