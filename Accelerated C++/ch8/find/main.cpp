
//
// Created by Insomnia on 2018/5/5.
// MIT License
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> randomVec(int len, int maxNum);

void printVec(vector<int> vec);

template<class In, class X>
int findVec(In begin, In end, const X &x);

int main() {
    vector<int> vec = randomVec(10, 50);
    printVec(vec);
    int index = findVec(vec.begin(), vec.end(), 20);
    cout << index;

    return 0;
}

template<class In, class X>
int findVec(In begin, In end, const X &x) {
    int i = 0;
    while (begin != end && *begin != x) {
        ++begin;
        ++i;
    }
    return i;
}

void printVec(vector<int> vec) {
    for (vector<int>::const_iterator it = vec.begin(); it < vec.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}

vector<int> randomVec(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));

    for (int i = 0; i < len; ++i) {
        int temp = rand() % maxNum;
        tempVec.push_back(temp);
    }
    sort(tempVec.begin(), tempVec.end());
    return tempVec;
}


