//
// Created by Insofan on 2018/4/15.
// MIT License
// 并没有搞定 ^-^

#include <iostream>
#include <vector>

using namespace std;

void swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void display(const vector<int> *vec) {
    if (!vec) {
        cout << "display(): the vector pointer is 0\n";
    }
    for (int ix = 0; ix < vec->size(); ix++) {
        cout << (*vec)[ix] << ' ';
    }
    cout << endl;
    cout << "<<------------------------------>>" << endl;
}

void bubbleSort(vector<int> *vec) {
    cout << vec->size() << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < vec->size(); j++) {
            if ((*vec)[i] > (*vec)[j]) {
                swap((*vec)[i], (*vec)[j]);
            }
        }
    }
}


int main() {
    int         ia[8] = {8, 32, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);
    cout << "vector before sort: " << endl;
    display(&vec);
    cout << "vector after sort: " << endl;
    bubbleSort(&vec);
    display(&vec);

    return 0;
}


