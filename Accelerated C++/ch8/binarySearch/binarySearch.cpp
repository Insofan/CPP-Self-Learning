//
// Created by Insomnia on 2018/5/5.
// MIT License
//

#include <iostream>
#include "../../RandomVec/randomVec.h"

using namespace std;

template<class Ran, class X>
bool binarySearch(Ran begin, Ran end, const X &x);

int main() {
    vector<int> vec = randomVector(10, 20);
    sort(vec.begin(), vec.end());
    display(vec);
    bool res = binarySearch(vec.begin(), vec.end(), 10);
    cout << "result " << res << endl;


    return 0;
}

template<class Ran, class X>
bool binarySearch(Ran begin, Ran end, const X &x) {
    while (begin < end) {
        Ran mid = begin + (end - begin) / 2;
        if ( x < *mid) {
            end = mid;
        } else if (x > *mid) {
           begin = mid + 1;
        }else {
            return true;
        }
    }
    return false;
}
