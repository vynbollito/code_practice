/* -----------------
    Object Literals
-------------------- */
/*
    var was in prev versions, but is outdated, so don't use
    use let or const
    const - constant
    {} - object literal sintax 
    OBJ: is a collection of key value pairs
 */
const circle = {
    // These are properties: radius and location
    radius: 1,
    // obj
    location: {
        x: 1,
        y: 1
    },
    // This is a method. It is said that if an obj has a method then it has behaviour
    draw: function () {
        console.log("Draw a circle");
    }
};
circle.draw();

/* -------------
    Factories
------------- */
// If an obj has a method and that obj need to me duplicaded it will appear as many times as number of objs. 
// For avoiding repetitive code, so instead of this: 
/*
const rect = {
    side: 1,
    location: {
        x: 1,
        y: 1
    },
    draw: function(){
        console.log("Draw a circle");
    } 
};   
*/

// Try this: 
// Factory function
function createSquare(side) {
    return {
        // es6 will allow us to simply us the params as properties
        // only if the key and the value as called the same
        side, // location seems missing but is omitted in order to focus on the factory process
        draw: function () {
            console.log("Draw a square with side: " + side);
        }
    };
}
const square = createSquare(5);
square.draw();

/* ---------------
    Constructors
------------------ */
// Another way to create an object is via constructor
// The constructor must start with Uppercase
function Triangle(side) {
    // 2. Point to the global object. Since we have the 'new' in line 74
    // _this_, is referenced to Triangle from line 65
    this.side = side;
    this.display = function () {
        console.log("The side of the triangle is: " + side);
    };
}
// 1. create an empty object
const triangle = new Triangle(15);
triangle.display();

// Both the factory and constructor are nothing but FUNCTIONS to JavaScript

/* -----------------------
    Constructor Property
-------------------------- */
// References used to construct/create an obj
/*
    When an obj is created Object() constructor is used
    for example: 
    let x = {};

    is like if we wrote
    let x = new Object();
        So the constructor will be Object()

    other build-in constructors are: 
         CONSTRUCTOR         LITERALS
        -------------------------------
        new String();    |   '' "" ``
        new Boolean();   |   true false
        new Number();    |   1, 2, 3, ...
        new Function();  |   

    So, every object has a construction property and that references the
    function that was used to create that object
*/

/* -----------------------
    Functions are objects
-------------------------- */
/** If we run this in the console
 * Hexagon.name >> "Hexagon"
 * Hexagon.length >> 1 (num of arguments)
 * 
 * Lets use Function() to create our object using the following example
 **/

function Hexagon(side) {
    this.side = side;
    this.display = function () {
        console.log("The side of the hexagon is: " + side);
    };
}

const hexagon = new Hexagon(8);
hexagon.display();

/**
 * So this above will be created using Function();
    PARAMS: 
     side, because is the expected parameter,
    `` for multiple lines of code
*/
const Hexa = new Function('side', `
    this.side = side;
    this.display = function(){
        console.log("The side of the hexagon is: "+side);
    }
`);
// Now if we create an object it will display your console msg
const hexa = new Hexa(44);
hexa.display();
// {side: 44, display f}

/* Methods in our functions */
// PARAMS:
// {} is this. It is the context, the target
// all the parameters 1, 2, 3, 'txt', ...
Hexa.call({}, 1); // calls a method of an obj, substituting another obj for the current obj
// this above is like: const hexa = new Hexa(44);
// where _new_ is the empty object and _44_ is the parameter

// In here apply is useful for several params alreay in an array
Hexa.apply({}, [1, 2, 3, 4]);

/* -----------------------------
    Value and Reference types 
-------------------------------- */
/*
    Value:  Copied by value
        Number
        String
        Boolean
        Symbol
        undefined
        null
    Reference: Copied by reference
        object
        functions, also objs
        arrays, yep! objs too XD
*/
// Since this are 
let x = 10;
let y = x;
x = 20;
// This will display x = 20 and y = 10
// Bcs the value was copied, not the reference, since the variables were value types

let i = {
    value: 99
};
let j = i;
i.value = 77;
// In here the address is copied so they have access to that memory space
// Eg2:
let number = 55;

function increase(number) {
    number++;
}
increase(number);
console.log(number); // >> 10

// Passed as reference
let addressNumber = {
    value: 310
};

function getAddressNumber(addNum) {
    addNum.value -= 300;
}
getAddressNumber(addressNumber);
console.log(addressNumber);

/* -----------------------------
    Adding|Removing Properties
-------------------------------- */
/**
 * Once you create an obj you can add or delete some properties
 */
const hexa2 = new Hexa(3);
// Adding a property
hexa2.location = { x:1 };
// Another way to add 
// I should use the dot notation instead but was written in this way
// for learning purpose
hexa2['location'] = { x:1 };
console.log(hexa2.location.x);

// The second way can be useful when we don't know that will be 'asked' until runtime
// also when using 'strange'|with spaces|... values
const propertyName = 'location-x';
hexa2[propertyName] = { x:1 };

// Delete a property
delete hexa2.location;

/* ----------------------------
    Enumerating Properties
------------------------------- */
// In every iteration key will hold a value of one key in this object
for (let key in hexa2){
    // This will display both, the name of the property|method of the object
    // and its value
    // console.log(key, hexa2[key]);
    
    // If we want to display only the properties we may use
    if( typeof hexa2[key] !== 'function')
        console.log(key, hexa2[key]);
}

// Another useful way is (They will be displayed as an array):
console.log(Object.keys(hexa2));

// To know if our object has certain property: 
if ('side' in hexa2)
    console.log('YE! hexa2 does have _side_ property');

/* -------------
    Abstraction
---------------- */