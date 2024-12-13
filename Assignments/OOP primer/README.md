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

### Abstraction
#### Definition: 
##### The process of identifying and focusing on the essential features of an object while ignoring irrelevant details.
#### Example:
##### A Car class can be abstracted to include methods like start(), stop(), accelerate(), without needing to know the intricate details of the engine's mechanics.

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

 ### Collections and Iterators
 #### Definition:
 ##### Collections: Data structures that hold groups of objects (e.g., std::vector, std::list, std::map in C++).
 ##### Iterators: Objects that allow you to traverse through the elements of a collection.
 #### Example:
 ##### std::vector<int> numbers = {1, 2, 3, 4}; 
##### for (auto it = numbers.begin(); it != numbers.end(); ++it) {
#####  std::cout << *it << " "; 
##### }

 ### Composition
 #### Definition: 
 ##### A "has-a" relationship between classes, where one class contains an object of another class as a member.
 #### Example: 
 ##### class Engine {
##### public:
#####  void start() { /* ... */ }
##### };
##### class Car {
##### private:
#####  Engine engine; 
##### public:
#####  void start() { engine.start(); } 
##### };
 
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
 
 ### Encapsulation
 #### Definition: 
 ##### Bundling data (attributes) and methods that operate on that data within a single unit (class). This hides the internal implementation details.
 #### Example: 
 ##### The Car class example above encapsulates the internal workings of the car's engine within the start() method.
 
 Exception Handling
 ### File I/O in OOP
 #### Definition: 
 ##### Using objects and classes to read from and write to files.
 #### Example:
 ##### std::ofstream outputFile("data.txt"); 
##### outputFile << "Hello, world!" << std::endl; 
##### outputFile.close();

### Friends
#### Definition:
##### A special keyword in C++ that grants a function or another class access to the private and protected members of a class.
#### Example: 
##### class MyClass {
##### private:
#####  int data;
##### public:
#####  friend void printData(MyClass obj); // Declare printData as a friend
##### };
##### void printData(MyClass obj) {
#####  std::cout << "Data: " << obj.data << std::endl; // Access private member
##### }

 Generics and Templates
 
### Inheritance
#### Definition: 
##### A mechanism that allows a new class (derived class) to inherit properties and behaviors from an existing class (base class).
#### Example: 
##### class Animal {
##### public:
#####  void eat() { std::cout << "Eating" << std::endl; }
##### };
##### class Dog : public Animal { 
##### public:
#####  void bark() { std::cout << "Woof!" << std::endl; }
##### };

 ### Instance Variable
 #### Definition: 
 ##### A variable that belongs to a specific object of a class.
 #### Example: 
 ##### In the Dog class, name is an instance variable, as each Dog object will have its own unique name.
 
 ### Member Variable
 #### Definition:
 ##### A general term for both class variables and instance variables.
 
 ### Memory Management (Garbage Collection, Pointers)
 #### Definition: 
 ##### Pointers: Variables that store memory addresses.
##### Garbage Collection: Automatic memory management where the system reclaims unused memory. (Not typically available in standard C++)
#### Example: 
##### int* ptr = new int; 
##### *ptr = 42; 
##### // ... 
##### delete ptr; // Manually deallocate memory

 ### Method Overloading
 #### Definition: 
 ##### When a class has multiple methods with the same name but different parameters.
 #### Example: 
 ##### class Calculator {
##### public:
#####  int add(int a, int b) {

 ### Method
 #### Definition: 
 ##### Functions that define the actions or behaviors of an object.
 #### Example: 
 ##### In the Dog class, bark() is a method that defines the action of the dog barking.
 
 Multiple Inheritance
 Multithreading in OOP (time permitting)
### Object Relationships (Association, Aggregation, Composition)
#### Definition: 
##### Describe how objects interact and relate to each other. Common types include association, aggregation, and composition.
##### Aggregation: A weaker form of composition, where an object "owns" another object but does not have exclusive ownership.
##### Association: A general term for any kind of relationship between objects, including one-to-one, one-to-many, many-to-many.
#### Example:
##### 1. A University class may have an aggregation relationship with Student objects. The university owns the student records, but the student can exist independently.
##### 2. A Customer class may have an association with an Order class, where one customer can place many orders.

 Object-Oriented Design Principles
 ### Operator Overloading
 #### Definition: 
 ##### Redefining the behavior of operators (e.g., +, -, *, ==) for user-defined classes.
 #### Example: 
##### class Complex {
##### public:
#####  Complex operator+(const Complex& other) { 
#####    // Implement complex number addition 
#####  }
##### };

 Overloading
 ### Polymorphism
 #### Definition: 
 ##### The ability of an object to take on many forms. 
 #### Example:
 ##### class Animal {
##### public:
#####  virtual void makeSound() { std::cout << "Generic sound" << std::endl; }
##### };
##### class Dog : public Animal {
##### public:
#####  void makeSound() override { std::cout << "Woof!" << std::endl; }
##### };
 Public / Private / Protected
 SOLID Principles
 ### Static (Methods and Variables)
 #### Definition: 
 ##### Static Method: A method that belongs to the class itself, not to any specific object. Accessed using the class name.
##### Static Variable: A variable shared by all objects of a class.
#### Example: 
##### See the Counter class example above.

 Testing in OOP (Unit Testing, Test-Driven Development)
 UML Diagrams and Modeling
 Virtual
