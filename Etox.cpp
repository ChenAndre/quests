//Student ID: 20501763


#include <iostream>
#include <sstream>
#include <cmath> // needed for sqrt and exp(x) which is same as e^x
#include <cstdlib> // for exit()
using namespace std;

double etox_5_terms(double x) {
    //we can use string literals
    double term1 = 1;           
    double term2 = x;           
    double term3 = (x * x) / 2; 
    double term4 = (x * x * x) / 6; 
    double term5 = (x * x * x * x) / 24; 

    double result = term1 + term2 + term3 + term4 + term5;
    return result;

}
int main(int argc, char **argv) {
 string user_input;
 double x;
 cout <<"Enter a value for x: ";
 getline(cin, user_input); //does not stop at the first whitesspace and reads the whole user input cuz of getline
 istringstream(user_input) >>x;

 cout << etox_5_terms(x) << "\n";

 return 0;
}
