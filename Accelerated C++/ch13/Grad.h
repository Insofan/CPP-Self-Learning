//
// Created by Insomnia on 2018/5/16.
// MIT License
//

#ifndef PROJECT_GRAD_H
#define PROJECT_GRAD_H

#include "Core.h"
#include <iostream>

using namespace std;

class Grad : public Core {
public:
    Grad();

    Grad(istream &);

    double grade() const;

    istream &read(istream &);

private:
    double thesis;
};


#endif //PROJECT_GRAD_H
