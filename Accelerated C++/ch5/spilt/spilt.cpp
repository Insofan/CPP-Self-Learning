//
// Created by Insofan on 2018/4/29.
// MIT License
//

#include <vector>
#include "spilt.h"

using namespace std;

vector<string> spilt(const string s) {
    vector<string> ret;
    typedef string::size_type stringSize;
    stringSize i = 0;
    while (i != s.size()) {
        while (i != s.size() && isspace(s[i])) {
            ++i;
        }
        stringSize j = i;
        while (j != s.size() && !isspace(s[j])) {
            ++j;
        }
        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}
