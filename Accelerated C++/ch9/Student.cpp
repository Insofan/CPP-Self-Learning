//
// Created by Insomnia on 2018/5/6.
// MIT License
//

#include "Student.h"
#include <iostream>

using namespace std;

istream& Student::read(std::istream &in) {
    in >> name >> midterm >> fina;
    readHw(in, homework);
    return in;
}

bool compare(const Student & x, const Student &y) {
    return x.name() < y.name();
}