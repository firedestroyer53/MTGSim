#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string> 
#include <algorithm>
#include <vector>
using std::string;
using std::vector;

template <typename T>
bool vectorContains(const vector<T>& vec, const T& value) {
    // Use std::find to check if value is in vec
    return std::find(vec.begin(), vec.end(), value) != vec.end();
}

string removeSpaces(string s) {
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    return s;
}

#endif // UTILITY_HPP