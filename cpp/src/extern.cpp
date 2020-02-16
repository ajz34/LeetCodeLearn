#include "extern.h"

string& ltrim(string& str) {
    auto it2 = find_if(str.begin(), str.end(), [](char ch) { return !isspace(ch); });
    str.erase(str.begin(), it2);
    return str;
}

string& rtrim(string& str) {
    auto it1 = find_if(str.rbegin(), str.rend(), [](char ch) { return !isspace(ch); });
    str.erase(it1.base(), str.end());
    return str;
}

string& trim(string& str) {
    return ltrim(rtrim(str));
}
