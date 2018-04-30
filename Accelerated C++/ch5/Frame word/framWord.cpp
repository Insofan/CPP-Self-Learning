//
// Created by Insofan on 2018/4/29.
// MIT License
//

#include "framWord.h"
#include <algorithm>
#include <string>
#include <vector>

#include "framWord.h"

using std::string;
using std::vector;

string::size_type width(const vector<string> &v) {
    string::size_type maxLen = 0;

    for (vector<string>::size_type i = 0; i != v.size(); i++) {
       maxLen = max(maxLen, v[i].size());
    }
    return maxLen;
}

vector<string> frame(const vector<string> &v) {
    vector<string> rect;
    string::size_type maxLen = width(v);
    string border(maxLen + 4, '*');

    rect.push_back(border);

    for (vector<string>::size_type i = 0; i != v.size(); i++) {
        //*    wtf  ", 用string(maxLen - v[i].size(), ' ') 来打印空格
        rect.push_back("* " + v[i] + string(maxLen - v[i].size(), ' ') + " *");
    }

    //write the bottom border
    rect.push_back(border);
    return rect;
}
