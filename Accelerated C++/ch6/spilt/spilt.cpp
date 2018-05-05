//
// Created by Insofan on 2018/4/29.
// MIT License
//

#include <vector>
#include "spilt.h"

using namespace std;
bool space(char c) {
    return isspace(c);
}

bool notSpace(char c) {
    return !isspace(c);
}

vector<string> spilt(const string s) {
//    vector<string> ret;
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while (i != s.end()) {
        i = find_if(i, s.end(), notSpace);
       iter j = find_if(i, s.end(), space);
       if (i != s.end()) {
           ret.push_back(string(i, j));
           i = j;
       }
    }
    return ret;
}
