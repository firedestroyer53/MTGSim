#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string> 
#include <algorithm>
using std::string;

string removeSpaces(string s) {
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    return s;
}

#endif // UTILITY_HPP