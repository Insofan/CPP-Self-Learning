//
// Created by Insomnia on 2018/4/26.
//

#include "median.h"

double median(vector<double> homework) {
    int size = homework.size();
    int mid = size / 2;
    return size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
}
