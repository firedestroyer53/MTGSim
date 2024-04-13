#include "utility.hpp"
#include <algorithm>

string removeSpaces(string s) {
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    return s;
}