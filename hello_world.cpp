// Student ID: 20501763
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    
    /*
    cout << "Hello world" << endl;
    cout << "This is a new line" << endl << "This text comes after endl" << endl; //demonstration of endl
    
    */


    //observe how we take user input
    cout << "Enter your name: ";
    string name;
    getline(cin, name);
    cout << "Hello, " << name<< "!" << endl;
    return 0;
}



