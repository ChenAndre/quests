/**
 * @file oopquickref.cpp
 * @brief A quick reference guide to Object-Oriented Programming (OOP) concepts in C++.
 * 
 * This file demonstrates the following OOP concepts:
 * - Classes and Objects
 * - Inheritance
 * - Polymorphism
 * - Virtual Functions
 * - Method Overriding
 * 
 * The example includes a base class `Animal` and two derived classes `Dog` and `Cat`.
 * Each class has a constructor and a method to make a sound, demonstrating polymorphism
 * through virtual functions.
 * 
 * @class Animal
 * @brief Base class representing a generic animal.
 * 
 * @fn Animal::Animal(string name)
 * @brief Constructor to initialize the animal's name.
 * @param name The name of the animal.
 * 
 * @fn Animal::makeSound() const
 * @brief Virtual function to make a sound. Can be overridden by derived classes.
 * 
 * @fn Animal::getName() const
 * @brief Getter function for the animal's name.
 * @return The name of the animal.
 * 
 * @class Dog
 * @brief Derived class representing a dog.
 * 
 * @fn Dog::Dog(string name)
 * @brief Constructor to initialize the dog's name.
 * @param name The name of the dog.
 * 
 * @fn Dog::makeSound() const
 * @brief Overridden function to make a barking sound.
 * 
 * @class Cat
 * @brief Derived class representing a cat.
 * 
 * @fn Cat::Cat(string name)
 * @brief Constructor to initialize the cat's name.
 * @param name The name of the cat.
 * 
 * @fn Cat::makeSound() const
 * @brief Overridden function to make a meowing sound.
 * 
 * @fn main()
 * @brief Main function demonstrating polymorphism with an array of animal pointers.
 * @return int Exit status of the program.
 */
#include <iostream>
#include <string>
using namespace std;

// Base class
class Animal {
public:
    // Constructor
    Animal(string name) : name(name) {}

    // Virtual function for polymorphism
    virtual void makeSound() const {
        cout << name << " makes a sound." << endl;
    }

    // Getter for name
    string getName() const {
        return name;
    }

protected:
    string name;
};

// Derived class
class Dog : public Animal {
public:
    // Constructor
    Dog(string name) : Animal(name) {}

    // Overriding the base class function
    void makeSound() const override {
        cout << name << " barks." << endl;
    }
};

// Another derived class
class Cat : public Animal {
public:
    // Constructor
    Cat(string name) : Animal(name) {}

    // Overriding the base class function
    void makeSound() const override {
        cout << name << " meows." << endl;
    }
};

// Main function
int main() {
    // Creating objects of derived classes
    Dog dog("Buddy");
    Cat cat("Whiskers");

    // Using polymorphism
    Animal* animals[] = { &dog, &cat };
    for (Animal* animal : animals) {
        animal->makeSound();
    }

    return 0;
}