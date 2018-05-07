//
// Created by Insomnia on 2018/5/6.
// MIT License
//
#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <iostream>

class Student {

private:
    std::string name;
    double midterm, final;
    std::vector<double > homework;

public:
    std::istream& read(std::istream&);
    double grade() const;

};


#endif //PROJECT_STUDENT_H
