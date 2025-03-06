//Student ID: 20501763
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Pet.h"
using namespace std;

string Pet::make_a_name(int len) {
    string vowels = "aeiou";
    string consonants = "bcdfghjklmnpqrstvwxyz";
    string name;

    if (len <= 0) {
        return name;
    }

    // we use a consonant if the rand % 2 is gonna be 0
    bool useConsonant = (rand() % 2 == 0);

    for (int i = 0; i < len; ++i) {
        if (useConsonant) {
            int index = rand() % consonants.size();
            name += consonants[index];
        } else {
            int index = rand() % vowels.size();
            name += vowels[index];
        }
        useConsonant = !useConsonant;
    }

    return name;
}

size_t Pet::_population = 0;


Pet::Pet(string name, long id, int num_limbs) : _name(name), _id(id), _num_limbs(num_limbs) {
    _population++;
}

// deconstructor tings 
Pet::~Pet() {
    _population--;
}

string Pet::get_name() const {
    return _name;
}

long Pet::get_id() const {
    return _id;
}

int Pet::get_num_limbs() const {
    return _num_limbs;
}

bool Pet::set_name(string name) {
    if (name.empty()) {
        return false;
    }
    _name = name;
    return true;
}

bool Pet::set_id(long id) {
    if (id < 0) {
        return false;
    }
    _id = id;
    return true;
}

bool Pet::set_num_limbs(int num_limbs) {
    if (num_limbs < 0) {
        return false;
    }
    _num_limbs = num_limbs;
    return true;
}

string Pet::to_string() const {
    ostringstream oss;
    oss << "(Name: " << _name << ", ID: " << _id << ", Limb Count: " << _num_limbs << ")";
    return oss.str();
}

void Pet::get_n_pets(size_t n, vector<Pet>& pets, int name_len) {
    pets.resize(n);
    long prev_id = 0;
    for (size_t i = 0; i < n; ++i) {
        long id = prev_id + 1 + (rand() % 10);

        pets[i].set_id(id);
        
        pets[i].set_num_limbs(rand() % 9);
        string name = Pet::make_a_name(name_len);
        pets[i].set_name(name);
        prev_id = id;
    }
}



bool operator==(const Pet& pet1, const Pet& pet2) {
    return (pet1.get_name() == pet2.get_name()) &&
           (pet1.get_id() == pet2.get_id()) &&
           (pet1.get_num_limbs() == pet2.get_num_limbs());
}

bool operator!=(const Pet& pet1, const Pet& pet2) {
    return !(pet1 == pet2);
}

ostream& operator<<(ostream& os, const Pet& pet) {
    os << pet.to_string();
    return os;
}