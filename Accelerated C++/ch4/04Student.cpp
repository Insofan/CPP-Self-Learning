//
// Created by Insofan on 2018/4/23.
// MIT License
//

#include "04Student.h"

using std::istream;
using std::vector;

bool compare(const Student &x, const Student &y) {
    return x.name < y.name;
}

istream &read(istream &is, Student &s) {
    is >> s.name >> s.midterm >> s.final;
    readHw(is, s.homework);
    return is;
}

istream &readHw(istream &in, vector<double> &hw) {
    if (in) {
        hw.clear();

        double x;

        while (in >> x) {
            hw.push_back(x);
            in.clear();
        }
        return in;
    }
}
