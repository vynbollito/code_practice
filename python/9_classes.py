'''
Simple class example
'''
class Point:
    # functions
    def move(self):
        print('move')
    
    def draw(self):
        print(draw)


# instances    
point_one = Point()
# attributes can be set anywhere in program
point_one.x = 10
point_one.y = 20
print(point_one.y)
point_one.move()

'''
Constructor
'''
class Point:
    # constructor
    def __init__(self, x, y, name):
        super().__init__()
        self.x = x
        self.y = y
        self.name = name

    # functions
    # self, reference to current obj. == this
    def move(self):
        print('move')
    
    def draw(self):
        print('draw')

    def salute(self):
        print(f'hi {self.name}!')

point = Point(10, 20, 'fab')
point.salute()
print(point.y)

'''
Inheritance
'''
class Mammal:
    def walk(self):
        print('walk')

# for the inheritance use the parentesis and the name of parent class
class Cat(Mammal):
    # pass, for ignoring the class is empty
    pass

class Dog(Mammal):
    def bark(self):
        print('bark')

dog = Dog()
print('dog here ')
dog.bark()
dog.walk()
cat = Cat()
print('cat here ')
cat.walk()

