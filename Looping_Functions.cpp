// Student ID: 20501763
// TODO - Replace the number above with your actual Student ID
//
// Looping_Functions.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <cmath> //for the last quest
using namespace std;
// Give the user 6 chances to guess the secret number n (0-10). If they get it,
// say so and return true. Else say so and return false.


//n should be a secret number not revealed to the user
bool play_game(int n) {

    int guesses = 6;
    int secretnum = n;
    string input;
    //int attempts = 0
    std::cout << "Welcome to my number guessing game" << "\n" << "\n";

    int attempts = 0;
    for (int i = 0; i <= guesses; i++){
        int guess;
        attempts++; 
        cout << "Enter your guess: \n";

        std::getline(cin, input);

        istringstream iss(input);
        if (!(iss >> guess)) {
            guess = 0;
        }

        cout << "You entered: " << guess << "\n";

        if(i== guesses-1){

            cout << "\n" << "I'm sorry. You didn't find my number. \nIt was " <<secretnum;
            return false;
            break;
        }

        if(guess == secretnum){
            cout << "You found it in " << attempts << " " << "guess(es)."<< endl;
            return true;
            cout << "\n";
            break;


        
        

        }
    }
    return false;
}
        

// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term.


double etox(double x, size_t n) {
    double result = 0.0;
    double term = 1.0;  // the first term in e^x - 1 is x

   
    for (size_t k = 0; k < n; k++) {
        result += term;
        term *= x / (k + 1);  
    }

    return result;
}

// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c){
    size_t count = 0; //size_t stores lots lots more than int js cant do negative

    for (size_t i = 0; i < s.length(); i++){
     // using size_t for iterator i bc s.length() returns size_t
        if (s[i] == c){
            count++;
        }
    }
    return count;
}

// Use Euclid's algorithm to calculate the GGCD of the given numbers

size_t gcd(size_t a, size_t b) {
    if (b == 0) {
        return a; // Base case: when b is 0, a is the GCD
    }
    return gcd(b, a % b); // Recursive case

}


std::string get_ap_terms(int a, int d, size_t n) {
    std::stringstream AP;
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) {
            AP << ",";
        }
        // signed arithmetic only
        AP << (a + static_cast<int>(i) * d);
    }
    return AP.str();
}


   
// Return a string of the form n1,n2,n3,... for the given GP.
std::string get_gp_terms(double a, double r, size_t n) {
    std::stringstream GP;
    double term = a; // initialize term to a
    for (size_t i = 0; i < n; ++i) {
        if (i > 0) {
            GP << ",";
        }
        GP << term; //because we arent able to use the pow function from math library ughssfewaewawewfwfwfewdfw
        term *= r; 
    }
    return GP.str();
}


double get_nth_fibonacci_number(size_t n) {
    if (n == 0) return 0.0;
    if (n <= 2) return 1.0;

    double a = 1.0, b = 1.0;
    for (size_t i = 3; i <= n; ++i) {
        double temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}