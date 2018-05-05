//
// Created by Insofan on 2018/5/1.
// MIT License
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool notUrlChar(char c) {
    static const string urlCh = "~;/?:@=&$-_.+!*'(),";
    return !(isalnum(c) || find(urlCh.begin(), urlCh.end(), c) != urlCh.end());
}

string::const_iterator urlBeg(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, notUrlChar);
}

vector<string> findUrls(const string s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    while (b != e) {
        b = urlBeg(b, e);

        if (b != e) {
            iter after = urlEnd(b, e);
            ret.push_back(string(b, after));
            b = after;
        }
    }
    ret;
}

int main() {
    cout << "url" << endl;

    return 0;
}




