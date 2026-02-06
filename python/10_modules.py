'''
Modules
Each file is called module and help organize code
into multiple files
'''
# brings all the members
from ecommerce import converters
print(converters.kg_to_lbs(80))
print(converters.lbs_to_kgs(177.77777777777777))

# get only a single or some members from the module
# and it can be called directly
from ecommerce.converters import kg_to_lbs
print(kg_to_lbs(35))


'''
Package
Container of multiple modules, in file sys terms = directory
Requires a file __init__.py by default
ecommerce -> the package
shipping -> a module
'''
# import ecommerce.shipping
# so, for calling
# ecommerce.shipping.calc_shipping()
# OR import a single or more methods
# from ecommerce.shipping import calc_shipping
# calc_shipping()
# OR import the module
# from ecommerce import shipping
# shipping.calc_shipping()

'''
Files and Directories
'''
from pathlib import Path
# Relative path
# Path() is args is empty it will reference current directory
path = Path('ecommerce')
# only validates if it exists or not 
print(path.exists())

print('--------------------------------')
path1 = Path('emails')
# creates a directory
print(path1.mkdir())
# remove a directory
print(path1.rmdir())

print('--------------------------------')
# Search for files and directories and process them
path2 = Path()
# * for all type files, can also be .py, .xml
# path2.glob('*') all directories and files
for file in path2.glob('*.py'):
    print(file)

