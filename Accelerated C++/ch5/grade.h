// Created by Insofan on 2018/4/26.
// MIT License
//

#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "Student.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student&);
bool fgrade(const Student&);
#endif //PROJECT_GRADE_H
