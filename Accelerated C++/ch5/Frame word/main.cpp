//
// Created by Insofan on 2018/4/29.
// MIT License
//

#include <iostream>
#include <vector>
#include "framWord.h"

using namespace std;

int main() {
    cout << "frame word" << endl;
    vector<string> p;
    p.push_back("this is an");
    p.push_back("example");
    p.push_back("to");
    p.push_back("illustrate");
    p.push_back("framing");

    ostream_iterator<string>ofile(cout, "\n");
    copy(p.begin(), p.end(), ofile);
    cout << endl;

    vector<string> f = frame(p);
    for (vector<string>::size_type i = 0; i != f.size(); i ++) {
        cout << f[i] << endl;
    }
    return 0;
}


