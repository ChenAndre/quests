//Student ID: 20501763

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Pet_Store.h"

using namespace std;

// Constructor: Creates a Pet_Store with n slots for pets
Pet_Store::Pet_Store(size_t n) {
    _pets.resize(n);
    _sort_order = NONE;
}

// Returns the current number of pets in the store
size_t Pet_Store::get_size() const {
    return _pets.size();
}

void Pet_Store::set_size(size_t n) {
    _pets.resize(n);
}


void Pet_Store::clear() {
    _pets.clear();
}


void Pet_Store::populate_with_n_random_pets(size_t n) {
    Pet::get_n_pets(n, _pets, 7);
    _sort_order = BY_ID;
}


bool Pet_Store::_id_compare(const Pet& p1, const Pet& p2) {
    return p1.get_id() < p2.get_id();
}


bool Pet_Store::_name_compare(const Pet& p1, const Pet& p2) {
    return p1.get_name() < p2.get_name();
}

//sorting by id
void Pet_Store::_sort_pets_by_id() {
    sort(_pets.begin(), _pets.end(), _id_compare);
    _sort_order = BY_ID;
}

//sortingg
void Pet_Store::_sort_pets_by_name() {
    sort(_pets.begin(), _pets.end(), _name_compare);
    _sort_order = BY_NAME;
}

//linear search by id
bool Pet_Store::find_pet_by_id_lin(long id, Pet& pet) {
    for (const auto& p : _pets) {
        if (p.get_id() == id) {
            pet = p;
            return true;
        }
    }
    return false;
}

// Linear search to find a pet by name
bool Pet_Store::find_pet_by_name_lin(string name, Pet& pet) {
    for (const auto& p : _pets) {
        if (p.get_name() == name) {
            pet = p;
            return true;
        }
    }
    return false;
}

// binary search by id (sorts first if needed)
bool Pet_Store::find_pet_by_id_bin(long id, Pet& pet) {
    if (_sort_order != BY_ID) {
        _sort_pets_by_id();
    }

    int left = 0;
    int right = static_cast<int>(_pets.size()) - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long current_id = _pets[mid].get_id();

        if (current_id == id) {
            result = mid;
            right = mid - 1;
        } else if (current_id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (result != -1) {
        pet = _pets[result];
        return true;
    }
    return false;
}

//binary search to find by name
bool Pet_Store::find_pet_by_name_bin(string name, Pet& pet) {
    if (_sort_order != BY_NAME) {
        _sort_pets_by_name();
    }

    int left = 0;
    int right = static_cast<int>(_pets.size()) - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        string current_name = _pets[mid].get_name();

        if (current_name == name) {
            result = mid;
            right = mid - 1;
        } else if (current_name < name) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (result != -1) {
        pet = _pets[result];
        return true;
    }
    return false;
}

// Converts pets from index n1 to n2 to a string representation
string Pet_Store::to_string(size_t n1, size_t n2) {
    ostringstream oss;
    size_t size = _pets.size();

    if (size == 0) {
        return "";
    }

    size_t start = max(n1, static_cast<size_t>(0));
    size_t end = min(n2, size - 1);

    if (start > end) {
        return "";
    }

    for (size_t i = start; i <= end; ++i) {
        oss << _pets[i].to_string() << "\n";
    }

    return oss.str();
}