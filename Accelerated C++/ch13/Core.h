//
// Created by Insomnia on 2018/5/16.
// MIT License
//


#ifndef PROJECT_CORE_H
#define PROJECT_CORE_H

#include <iostream>
//#include <>

using namespace std;

class Core {
public:
    Core();

    Core(istream &);

    string name() const;

    istream &read(istream &);

    double grade() const;

protected:
    istream &read_common(istream &);

    double midterm, final;
    vector<double> homework;

private:
    string n;
};


#endif //PROJECT_CORE_H
