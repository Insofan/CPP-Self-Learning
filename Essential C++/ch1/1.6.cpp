//
// Created by Insomnia on 2018/4/12.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number, sum = 0;
    vector<int> vecNumber;

    cout << "Please enter some integers: " << endl;

    while (cin >> number) {
        //在向量尾 加入一个数据
        vecNumber.push_back(number);
    }

    for (vector<int>::iterator itr = vecNumber.begin(), vecEnd = vecNumber.end(); itr != vecEnd; ++itr) {
        sum += *itr;
    }

    cout << "The sum is " << sum <<endl;
    double average = sum /vecNumber.size();
    cout << "The average is " << average << endl;

    return 0;
}
