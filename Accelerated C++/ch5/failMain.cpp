//
// Created by Insofan on 2018/4/29.
// MIT License
//

#include <iostream>
#include <algorithm>
#include "./grade.h"
#include "./Student.h"
#include <vector>

using namespace std;
int main() {
    vector<Student> vs;
    Student student;
    string::size_type maxLen = 0;
    while (read(cin, student)) {
        maxLen = max(maxLen, student.name.size());
        vs.push_back(student);
    }

    sort(vs.begin(), vs.end(), compare);
    vector<Student> fails = extractFails(vs);

    for (int i = 0; i < fails.size(); ++i)
        cout << fails[i].name << " fail " << grade(fails[i]) << endl;

    return 0;
}


