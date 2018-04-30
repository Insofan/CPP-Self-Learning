//
// Created by Insofan on 2018/4/29.
// MIT License
//

#include <iostream>
#include <vector>
#include "spilt.h"

int main() {
    using namespace std;
    string s;
    while (getline(cin, s)) {
        vector<string> v = spilt(s);
        for (vector<string>::size_type i = 0; i != v.size(); i++) {
            cout << v[i] << endl;
        }
    }

    return 0;
}


