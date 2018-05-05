//
// Created by Insomnia on 2018/5/5.
// MIT License
//

#ifndef PROJECT_MEDIAN_H
#define PROJECT_MEDIAN_H

#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

template<class T>
T median(vector<T> v) {
    typedef typename vector<T>::size_type vecSz;
    vecSz size = v.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }
    sort(v.begin(), v.end());
    vecSz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

#endif //PROJECT_MEDIAN_H
