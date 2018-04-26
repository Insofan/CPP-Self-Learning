//
// Created by Insofan on 2018/4/26.
// MIT License
//

#include <stdexcept>
#include <vector>
#include "grade.h"
#include "Student.h"
#include "median04.h"

using std::domain_error;  using std::vector;


// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, medianWtf(hw));
}

double grade(const Student& s)
{
    return grade(s.midterm, s.final, s.homework);
}
