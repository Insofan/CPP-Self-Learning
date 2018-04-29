
// Created by Insofan on 2018/4/26.
// MIT License
//

#include "Student.h"
#include "grade.h"

using std::istream;
using std::vector;
using namespace std;

bool compare(const Student &x, const Student &y) {
    return x.name < y.name;
}

istream &read(istream &is, Student &s) {
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;

    readHw(is, s.homework);  // read and store all the student's homework grades
    return is;
}

istream &readHw(istream &in, vector<double> &hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

vector<Student> extractFails(vector<Student> &students) {
//    vector<Student> pass, fail;
//    for (vector<Student>::size_type i = 0; i != students.size(); i++ ) {
//        if (fgrade(students[i])) {
//            fail.push_back(students[i]);
//        } else {
//            pass.push_back(students[i]);
//        }
//    }
//    students = pass;
    vector<Student> fail;
    vector<Student>::size_type i = 0;
    //这个size需要在while中写, 因为erase所以size是变化的如果提前写好,就会失效
    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            //用begin加索引号来删除指定位置
            students.erase(students.begin() + i);
        } else {
            ++i;
        }
    }
    return fail;
}
