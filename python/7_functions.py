'''
Basics
'''
def funcName(name, day, first_song, other_song):
    print('\tHi'+ name + '!')
    print('\tHope you are having a nice '+ day + ' :)')
    print('\tYou need to listen "' + first_song + '" and then another similar one like: "'+ other_song + '"')


# always leave 2 spaces with the end of a method
# define your methods before calling them
print('\nStart displaying...\n')
# positional args: values are set according to the order
# key_word: _goes at the end_ of the args and define for which 
# parameter will be saved
# by hierarchy all args are FIRST consider as positional args, 
# but if it finds the keyword it considerates it.
# At the end these are good for readability of the code
funcName('Fabs', 'afternoon', other_song='Blue Eyes', first_song='Ever and Ever')
print('\nend of code\n')


