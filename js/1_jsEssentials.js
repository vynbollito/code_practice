/* -------------
	Static vs Dynamic Language
		Dynamic can be modified during runtime
*/
let myName = 'nameInHere'; // >> string
console.log(typeof(myName));
myName = 1; 	// >> number 
console.log(typeof(myName));

/* -------------
	Primitives / Value types
		string, "" ''
		number, 123 12.34
		boolean, true false
     	undefined(by default), a type and also a value
     	null (clear the value of the var), is an obj type, it an be set to a variable
	
	Reference types 
    	Object 
     	Array, still an obj LOL
    	Function
------------- */ 
// Strings 
let txt = "text with some spaces";
console.log(txt.toUpperCase());
console.log(txt.toLowerCase());
console.log(txt.startsWith("$")); // boolean
console.log(txt.endsWith("$")); // boolean
console.log(txt.trim()); // "textwithsomespaces"
console.log(txt.length); // 21


// Declaring objs: instead of let name = 'chip_Cookies', age = 100;
let person = {'name': 'chipCookies', 'age': 100, 'status': 'studying', 'state': 'MX'};
console.log(person);

// Accessing by dot notation
person.status = 'summer_break';
console.log(person.status);

// Accessing by bracket notation
// In this example it would be better to use the dot notation, but I pretend to show how the notation works
person['state'] = 'world';
console.log(person.state);
/* 	
In here, is the perfect scenario por bracket notation.
	This can be useful during runtime 
	when we don't know which property 
	we'll be acessing to (eg):
*/
let selection = 'name';
person[selection] = 'chipCookiesAndMilk';

/* --------- ARRAYS --------- */
// order collection of elements
// let array = []; // empty array
let array = ['red', 'blue'];
console.log(array); // red blue
array[2] = 55;
console.log(array[0]);
console.log(array); // [ "red", "blue", 55 ]
console.log(array.length); // 3
console.log(array.push("purple")); // add a new element
console.log(array.pop()); // removes the last elem inserted
console.log(array.shift()); // removes the first elem from array
console.log(array.sort()); // if numbers and strings, then first nums then strings
array[5] = 22; // the lenth before this declaration was 3
console.log(array); // so in here the array is automatically filled with empty until the 5 position

function greet(name, lastName) {
    console.log('a function here. Your name is: ' + name + ' ' +lastName);   
}
// if we only pass a single arg lastName will appear undefined
greet('chipCookiesAndMilk');

// A function with a return value
function square(number) {
    return number * number;
}

console.log(square(5));
/* --------- FOR --------- */
// For of | For each, iterates by element rather by index
console.log(array);
for(let element of array){
    console.log(element);  // Array(3) [ "red", "blue", "purple" ]
    element = 'orange'; // this will only change the variable element not the value in the array
    console.log(element); // so we are not 'accessing at position' in the array, but just coping the value into a new variable
}// red // orange // blue // orange // pruple // orange
console.log(array); // Array(3) [ "red", "blue", "purple" ], yep the array was not modified

/* --------- SETS --------- */
// unorder collection of unique elements
let _set = new Set(/*we can also use the constructor to add elements*/);
_set.add(5).add(9).add(5); // 5 9, bcs 5 already exits
console.log(_set.size); 
console.log(_set.has(5)); // true // O(1), lookup, add, delete time complexity 
_set.add(8);
console.log(_set.delete(5)); // 9 8
console.log(_set.delete(5)); // false, it does not exist, it was prev removed
console.log(_set.values()); // 9 8 

for(let element of _set.values()){
    console.log(element);
}

function printValue(value){
    console.log(value);
}
// every element at _set will execute the printValue function 
_set.forEach(printValue);


/* --------- MAPS --------- */
// O(1) 
let map1 = new Map([["name", "Chip Cookies"],["age", 100], ["country", "MX"]]);

console.log(map1.get("name")); // Chip Cookies

map1.set("name", "Chip Cookies And Milk"); // will override the value

map1.delete("country"); // this will do nothing
console.log(map1.size); // 2

console.log(map1.has("country")); // false
map1.clear();
console.log(map1.entries()); // MapInterator { name => "Chip Cookies", age => 100 }

for(let entry of map1){
    console.log(entry); // ["name", "Chip Cookies"] // ["age", 100]
}
for(let entry of map1){
    console.log(entry[0]); // [0] returns the key, [1] returns the value // name age    
}

let phase = "This is a phase with spaces";
/* 
	0: T → 1
	​​1: h → 3
	​​2: i → 3
	​​3: s → 5
	​​4: " " → 5
	​​5: a → 3
	​​6: p → 2
	​​7: e → 2
	​​8: w → 1
	​​9: t → 1
	​​10: c → 1
*/
let mp = new Map();

for(let letter of phase){
	if(mp.has(letter))
		mp.set(letter, mp.get(letter)+1);
	else
		mp.set(letter, 1);
}
console.log(mp);
