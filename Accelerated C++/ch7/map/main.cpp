//
// Created by Insofan on 2018/5/2.
// MIT License
//

#include <iostream>
#include <map>

using namespace std;
int main() {
    string s;
    map<string, int> counters;
    while (cin >>s) {
        ++counters[s];
        if (counters.size()>2) {
            break;
        }
    }

    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }
    return 0;
}


