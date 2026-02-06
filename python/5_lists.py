'''
1D List
'''
# simple list
numbers = [8, 4, 2, 54, 0, 33, 87, 23, 88, 55, 99, -100, 99.9]
st = "  ";
print("\nOriginal list: ")
for i in numbers:
    st = st + str(i)+" "
print(st)

# starting point. Bc we don't have any number to start with, we'll use the first elem
max = numbers[0] 
for current_num in numbers:
    if current_num > max:
        max = current_num
print('\n  The largest number found was: '+str(max))
print("\n")

'''
2D List or more
'''
# row, column
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
print(f'matrix[2][1]: {matrix[2][1]}\n')

# list.pop() last elem in index
# list.index(x) fins the first elem with this value and returns index
# print(50 in list) >> False if not found
# .count(x) how many times does the elem is found in the list
# . sort()
# . reverse()
# . copy()
# 2:12

'''
Duplicated list validation exercise
'''
numbers_list = [2, 2, 4, 6, 3, 4, 6, 1]
uniques_list = []

for number in numbers_list:
    found = 0
    for unique in uniques_list:
        if number == unique:
            found = 1
            unique = len(uniques_list) + 1 # my break statement
    if found == 0:
        uniques_list.append(number)
print(uniques_list)

# simplied form, using python benefits
# clear() for 'starting over'
uniques_list.clear()
print('--------------------------------')
for number in numbers_list:
    if number not in uniques_list:
        uniques_list.append(number)
print(uniques_list)

'''
Tuples
'''
# tuple uses (). This structure are inmutable
# you can only count them or see their index. Nothing more
# access like arrays tuple = (1, 2, 3). tuple[0]

'''
Unpacking
'''
coordinates = (1, 2, 3)
# too complex
# result = coordinates[0] * coordinates[1] * coordinates[2]
# instead 
x = coordinates[0]
y = coordinates[1]
z = coordinates[2]

# still preally annoying
# try with UNPACKING it also works with lists
result = x * y * z
print(result)

