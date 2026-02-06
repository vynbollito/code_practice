'''
Simple exception handle
'''
try:
    age = int(input('Age: '))
    income = 2000
    risk = income / age
    print(f'Risk is: {risk}')
# applies to non numerica values
except ValueError:
    print('\t>>Error! Please, enter a integer to continue...')
# zero division
except ZeroDivisionError:
    print('\t>>Error! Your age cannot be zero')

