//
// Created by Insofan on 2018/4/29.
// MIT License
//


#ifndef PROJECT_FRAMWORD_H
#define PROJECT_FRAMWORD_H

#include <vector>
#include <string>

using namespace std;

std::string::size_type width(const std::vector<std::string> &v);

std::vector<std::string> frame(const std::vector<std::string> &v);

std::vector<std::string> vcat(const std::vector<std::string> &top,
                              const std::vector<std::string> &bottom);

std::vector<std::string> hcat(const std::vector<std::string> &left,
                              const std::vector<std::string> &right);

#endif //PROJECT_FRAMWORD_H
