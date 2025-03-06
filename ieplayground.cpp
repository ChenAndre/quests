#include <iostream>
#include <string>

using namespace std;

// function that demonstrates relational operators.
int main(){

    string him = "h"; //less efficient, generally we want to use char for string literals for space saving

    cout << him << "\n";


    bool tbool = (5 == 10);
    bool wbool = (5 != 10);
    bool NotZeroe = -5;   //nonzero values assigned to bool data type will always return 1, even neg nums

    //single quotes for chars and double quotes for a string 

    


    cout << "tbool is: " << tbool << endl;
    cout << "wbool is: " << wbool << endl;
    cout << "bool is: " << NotZeroe << endl;

    cout << (5 == 10) << endl;
    cout << (10 > 5) << endl;
    cout << ((5 >= 1) && (5 <= 10)) << endl;

    return 0;
}
