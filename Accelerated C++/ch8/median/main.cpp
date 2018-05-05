//Created by Insomnia on 2018/5/5.
// MIT License
//

#include <iostream>
#include<vector>
#include "median.h"

using namespace std;

vector<int> randomVec(int len, int maxNum);

int main() {
    //odd
    vector<int> vec = randomVec(5, 20);
    cout << "Odd" << endl;
    for (vector<int>::const_iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << (*iter) << " ";
    }
    cout << endl;
    cout << "mid: " << median(vec) << endl;

    //even
    vector<int> vecTwo = randomVec(6, 20);
    cout << "Even" << endl;
    for (vector<int>::const_iterator iter = vecTwo.begin(); iter != vecTwo.end(); iter++) {
        cout << (*iter) << " ";
    }
    cout << endl;
    cout << "mid: " << median(vecTwo) << endl;
    return 0;
}


vector<int> randomVec(int len, int maxNum) {
    vector<int> tempVec;
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        int tem = rand() % maxNum;
        tempVec.push_back(tem);
    }
    sort(tempVec.begin(), tempVec.end());
    return tempVec;
}


