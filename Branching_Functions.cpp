//Student ID: 20501763

//Blue Quest -03

#include <iostream>
#include <vector>
#include <array>
#include <algorithm> //we could have just used the std:: max_element for max element but meh
using namespace std;



    // This function returns the mean the three numbers passed
// in as parameters. Note that the mean may not be a round
// number. So you must use the double datatype for it.
double mean_of_3(int n1, int n2, int n3) {
    return ((n1 + n2 + n3)/3.0);
}


// This function returns the MAXIMUM of the 5 given numbers
int max_of_5(int n1, int n2, int n3, int n4, int n5) {
    int my_arr[] = {n1, n2, n3, n4, n5};  //compiler is able to deduce the size because I gave the elements
                                          //otherwise, you would have to input the size in the brackets :D
    //int size = sizeof(my_arr);//returns the amount of bytes since each integer uses 4, it will say size is 20, cuz thats the amount of bytes, but what we rly want is the size of the array in terms of n elements. This is how we will do it
    int size = sizeof(my_arr) / sizeof(my_arr[0]); //this will do 20/4 which gets u 5. Remember that each integer has 4 bytes and 20/4 gets us the 5 "n elements" that we know to be true
    int biggest = my_arr[0];                       // had a milisec thought where i thought of hardcoding to 0 but no, cuz what if everything else is negative, never hard code kids.

    for (int i = 1; i < size; i++){
        if (my_arr[i] > biggest){
            biggest = my_arr[i];
        }
        }
    
    return biggest;
}   



// This function returns the MINIMUM of the 5 given numbers
int min_of_5(int n1, int n2, int n3, int n4, int n5) {

    int my_arr[] = {n1, n2, n3, n4, n5};  //compiler is able to deduce the size because I gave the elements
                                          //otherwise, you would have to input the size in the brackets :D
    //int size = sizeof(my_arr);//returns the amount of bytes since each integer uses 4, it will say size is 20, cuz thats the amount of bytes, but what we rly want is the size of the array in terms of n elements. This is how we will do it
    int size = sizeof(my_arr) / sizeof(my_arr[0]); //this will do 20/4 which gets u 5. Remember that each integer has 4 bytes and 20/4 gets us the 5 "n elements" that we know to be true
    int smallest = my_arr[0];                       // had a milisec thought where i thought of hardcoding to 0 but no, cuz what if everything else is negative, never hard code kids.

    for (int i = 1; i < size; i++){
        if (my_arr[i] < smallest){
            smallest = my_arr[i];
        }
        }
    
    return smallest;


}
// Given three lengths, this function should return whether they can be the
// sides of some triangle. The heuristic you code should check if the
// sum of the two smallest sides is greater than or equal to the third side.
// Treat extreme cases as valid triangles. E.g. a+b == c means valid triangle.
// The challenge is to do it without using arrays
//WHAT THE FUCK WHY NO ARRAYS BRO I JUST SPENT LIKE 30 MINUTES ON THIS SHIT
//NOTE TO SELF ALWAYS READ INSTRUCTIONS BEFORE IMPLEMENTATIONS CAREFULLY SHEESH
bool sides_make_triangle(int a, int b, int c) {
    return (a + b >= c && a + c >= b && b + c >= a);
}

    /*
    int pirate_arr[] = {a, b, c};
    for (int i = 0; i < 3; i++){     //total of 9 iteratiosn thru ts function
        int sum = 0;
        for (int j = 0; j < 3; j++){
            if (i != j){
                sum += pirate_arr[j];
            }
        }
        //checked thrice its apart of the outer for loop scopee
        if (sum <= pirate_arr[i]){
            return false;
        }
        }

        */
    //elegant solution using the built in sort function, we will know that the two smallest sides should be greater
    //than the longest side, thus passing the triangle inequality theorem
    /*bool isValidTriangle(int a, int b, int c) {
    int sides[] = {a, b, c};
    std::sort(sides, sides + 3);
    return sides[0] + sides[1] > sides[2];
}*/

    //for my solution ill implement a nested for loop because thats something im a bit raw on
    //and it would be good practice to implement it in an unfamiliar language


// Given three angles as integer degrees, this function should return whether
// they can be internal angles of some triangle. Treat extreme cases as
// valid triangles. E.g. (0, 0, 180) is a valid triangle
bool angles_make_triangle(int A, int B, int C) {

    return (A + B + C <= 180);
}

// Return true if the year yyyy is a leap year and false if not.
//year must be evenly divisble by 4
//if the year is evenly divisible by 100 its not a leap year unless also divisible by 400




    //return (yyyy % 4 == 0 && yyyy % 100 != 0) or (yyyy % 400 == 0);

bool is_a_leap_year(int yyyy) {
    if (yyyy % 4 != 0) {
        return false;
    }
    if (yyyy % 100 == 0) {
        return yyyy % 400 == 0;
    }
    return true;

}
