//
// Created by Insofan on 2018/4/26.
// MIT License
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student&, const Student&);
std::istream& read(std::istream&, Student&);
std::istream& readHw(std::istream&, std::vector<double>&);
std::vector<Student> extractFails(std::vector<Student> & students);
#endif //PROJECT_STUDENT_H
