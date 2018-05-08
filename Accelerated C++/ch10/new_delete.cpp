//
// Created by Insomnia on 2018/5/8.
// MIT License
//

#include <iostream>

int main() {
    using namespace std;
    int *p = new int(42);

    ++*p;
    cout << *p << endl;
    delete p;
    ++*p;
    cout << *p << endl;

    return 0;
}


