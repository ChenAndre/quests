// Student ID: 20501763
// TODO - Replace the number above with your actual Student ID
// Eliza.cpp
// BLUE.Quest-05-Eliza
//
//
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

string lispify(string s) {
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == 's') {
            s.replace(i, 1, "th");
            ++i; 
        } else if (s[i] == 'S') {
            s.replace(i, 1, "Th");
            ++i;
        }
    }
    return s;
}


string rotate_vowels(string &s) {
    string vowels = "aeiouAEIOU";
    string rotated = "eiouaEIOUA";

    for (char &c : s) {
        size_t pos = vowels.find(c);
        if (pos != string::npos) {
            c = rotated[pos];
        }
    }
    return s; // Return the modified string
}

void enter() {
    cout << "What?" << endl;

    string user_input;
    while (true) {  // Infinite loop until user quits
        getline(cin, user_input);

        if (user_input.empty()) {
            cout << "What?" << endl;
            continue;   //for any instance in which continue statement is executed, it will go back to the while(true) loop
        }

        cout << "    " << user_input << "\n" << endl;

        if (user_input.find('!') != string::npos) {
            cout << "OMG! You don't say!! " << user_input << "!!!!!" << endl;
            continue;
        }

        if (user_input.find("why") != string::npos || user_input.find("what") != string::npos) {
            cout << "I'm sorry, I don't like questions that contain what or why." << endl;
            continue;
        }

        if (user_input.find('s') != string::npos || user_input.find('S') != string::npos) {
            cout << "Interethting. When did you thtop thtopping your thibilanth?" << endl;
            cout << lispify(user_input) << "! Sheesh! Now what?" << endl;
            continue;
        }

        if (user_input.find("Bye") != string::npos || user_input.find("Quit") != string::npos ||
            user_input.find("bye") != string::npos || user_input.find("quit") != string::npos) {
            cout << "Ok Bye. Nice being a force of change in your life." << endl;
            break;
        }

        int number = rand();
        int remainder = number % 10;

        if (remainder == 8 || remainder == 9) {
            cout << "Huh? Why do you say: " << user_input << "?" << endl;
        } else {
            rotate_vowels(user_input); // Modifies original string
            cout << user_input << "?" << endl;
        }
    }
}


