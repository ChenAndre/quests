// Student ID: 20501763
// TODO - Replace the number above with your actual Student ID
//
// Limerick.cpp
// BLUE-Quest-01
//
#include <iostream>
#include <sstream> // Need this for istringstream below
#include <cmath> // needed for sqrt
#include <cstdlib> // for exit()
using namespace std;



double eval_limerick(int dozen, int gross, int score) {
    double result = (dozen + gross + score + 3 * sqrt(4)) / 7 + 5 * 11;
    return result;
}


int main(int argc, char **argv) {
    int dozen, gross, score;

    if (argc < 4) {
        cerr << "Usage: limerick dozen-val gross-val score-val\n";
        exit(1);
    }
    istringstream(argv[1]) >> dozen;
    istringstream(argv[2]) >> gross;
    istringstream(argv[3]) >> score;

    // Invoke the eval_limerick function correctly and print the result
    double result = eval_limerick(dozen, gross, score);
    cout << result << endl;

    return 0;
}




// I'm using command line arguments below to let me test your program with
// various values from a batch file. You don't have to know the details for
// BLUE, but you're welcome to - Discuss in the forums any aspect of this
// program you don't understand.