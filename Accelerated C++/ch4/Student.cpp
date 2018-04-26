//
// Created by Insofan on 2018/4/26.
// MIT License
//

#include "Student.h"

using std::istream;
using std::vector;
bool compare(const Student& x, const Student& y) {
    return x.name < y.name;
}
istream& read(istream& is, Student & s) {
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;

    readHw(is, s.homework);  // read and store all the student's homework grades
    return is;
}

istream& readHw(istream& in, vector<double> &hw) {
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
