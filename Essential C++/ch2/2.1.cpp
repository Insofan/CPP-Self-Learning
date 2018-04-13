//
// Created by Insomnia on 2018/4/12.
//

#include <iostream>

using namespace std;

bool fibonElem(int, int &);


bool fibonElem(int pos, int &elem) {
    if (pos <= 0 || pos > 1024) {
        cerr << "Wrong position!";
        elem = 0;
        return false;
    }
    elem        = 1;
    //n1 , n2, 2, 3, 5
    int      n2 = 1;
    int      n1 = 1;
    for (int i  = 3; i <= pos; ++i) {
        elem = n2 + n1;
        n1   = n2;
        n2   = elem;
    }
    return true;
}

int main() {
    int  pos, elem;
    char ch;
    bool more = true;

    while (more) {
        cout << "Please enter a position: ";
        cin >> pos;
        if (fibonElem(pos, elem)) {
            cout << "element # " << pos
                 << " is " << elem << endl;
        } else {
            cout << "Sorry, could not calculate this element # " << pos << endl;
        }
        char continueStr;
        cout << "Would you like to continue? (y/n)" << endl;
        cin >> continueStr;
        if (continueStr == 'n') {
            more = false;
        } else {
            more = true;
        }
    }
    return 0;
}

