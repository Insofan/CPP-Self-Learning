//
// Created by Insofan on 2018/4/24.
// MIT License
//
#include <algorithm>
#include <istream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "median.h"
#include "grade.h"
#include "Student.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
//表示长度
using std::streamsize;
using std::vector;
using std::sort;
using std::domain_error;
using std::istream;
using std::max;

int main() {
    vector<Student> students;
    Student record;
    string::size_type maxLen = 0;
    while (read(cin, record)) {
        //find length of longest name
        maxLen = max(maxLen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student>::size_type i = 0; i != students.size(); ++i) {
        cout << "name " << students[i].name << string(maxLen + 1 - students[i].name.size(), ' ');
        //compute and write the grade
        try {
            double finalGrade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << finalGrade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
