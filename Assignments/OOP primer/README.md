# Terminology

## Key Words and Concepts

### Abstract Classes and Interfaces:
#### Definition:
##### Hiding the internal complexity of an object and only exposing essential features to the outside world. This simplifies interaction and reduces the risk of unintended consequences.
#### Example:
##### class Car {
##### public:
##### void start() { 
##### // Internal logic: engage starter motor, fuel injection, etc. 
##### std::cout << "Car started." << std::endl; 
##### }
##### };

### Classes and Objects:
#### Definition: 
##### Class: A blueprint or template that defines the properties (attributes) and behaviors (methods) of a set of objects.
##### Object: An instance of a class, representing a specific entity with its own set of data values.
#### Example: 
##### class Dog {
##### public:
#####  std::string name;
#####  void bark() { std::cout << "Woof!" << std::endl; }
##### };}
##### Dog myDog; // Create an object (instance) of the Dog class
##### myDog.name = "Buddy";
##### myDog.bark(); 

### Access Modifiers (Public, Private, Protected)
#### Definition: 
##### Control the visibility and accessibility of class members (attributes and methods).
##### Public: Accessible from anywhere.
##### Private: Accessible only within the class itself.
##### Protected: Accessible within the class and its derived classes.
#### Example: 
##### class Animal {
##### protected:
#####   int age; 
##### };
##### class Dog : public Animal {
##### public:
#####  void setAge(int a) { age = a; } // Accessing protected member
##### };
 
### Attributes / Properties
#### Definition: 
##### Data members of a class that represent the characteristics or state of an object.
#### Example: 
##### In the Dog class above, name is an attribute representing the dog's name.

 ### Class Variable
 #### Definition: 
 ##### A variable shared by all objects of a class. Declared with the static keyword.
 #### Example: 
 ##### class Counter {
##### public:
#####  static int count; 
##### };
##### int Counter::count = 0; 
##### Counter obj1, obj2; 
##### Counter::count++; 

 Classes and Objects
 Collections and Iterators
 Composition
 
 ### Constructors and Destructors
 #### Definition:
 ##### Constructor: A special method that initializes an object when it is created.
 ##### Destructor: A special method that cleans up an object's resources before it is destroyed.
 #### Example: 
 ##### class MyClass {
##### public:
#####  MyClass() { std::cout << "Constructor called" << std::endl; } 
#####  ~MyClass() { std::cout << "Destructor called" << std::endl; }
##### };

 Design Patterns (e.g., Singleton, Factory, Observer)
 Encapsulation
 Exception Handling
 File I/O in OOP
 Friends
 Generics and Templates
 Inheritance
 ### Instance Variable
 #### Definition: 
 ##### A variable that belongs to a specific object of a class.
 #### Example: 
 ##### In the Dog class, name is an instance variable, as each Dog object will have its own unique name.
 
 ### Member Variable
 #### Definition:
 ##### A general term for both class variables and instance variables.
 
 Memory Management (Garbage Collection, Pointers)
 Method Overloading
 ### Method
 #### Definition: 
 ##### Functions that define the actions or behaviors of an object.
 #### Example: 
 ##### In the Dog class, bark() is a method that defines the action of the dog barking.
 
 Multiple Inheritance
 Multithreading in OOP (time permitting)
 Object Relationships (Association, Aggregation, Composition)
 Object-Oriented Design Principles
 Operator Overloading
 Overloading
 Polymorphism
 Public / Private / Protected
 SOLID Principles
 Static (Methods and Variables)
 Testing in OOP (Unit Testing, Test-Driven Development)
 UML Diagrams and Modeling
 Virtual
