//
// Created by Insomnia on 2018/5/5.
// MIT License
//

#include "randomVec.h"
#include <vector>
using namespace std;
//template <class X>
vector<int> randomVector(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        int tem = rand() % maxNum;
        tempVec.push_back(tem);
    }
    display(tempVec);
    return tempVec;
}

template <class T>
void display(vector<T> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (i != vec.size() - 1) {
            cout << vec[i] << " -> ";
        } else {
            cout << vec[i];
        }
    }
    cout << endl;
}
