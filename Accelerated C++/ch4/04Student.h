//
// Created by Insofan on 2018/4/21.
// MIT License
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <iostream>
#include <string>
#include <vector>

//using namespace std;
using std::istream;  using std::vector;
struct Student {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student&, const Student&);
std::istream& read(std::istream&, Student&);
std::istream& readHw(std::istream&, std::vector<double>&);

#endif //PROJECT_STUDENT_H
