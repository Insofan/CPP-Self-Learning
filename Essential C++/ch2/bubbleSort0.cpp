//
// Created by Insofan on 2018/4/15.
// MIT License
//

#include <iostream>
#include <vector>

using namespace std;
void swap(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void display(vector<int> &vec) {
    if (!vec[0]) {
        cout << "display(): the vector pointer is 0\n";
    }
    for (int ix = 0; ix < vec.size(); ix++) {
        cout << vec[ix] << ' ';
    }

    cout << "\n" << "<<------------------------------>>" << endl;
}

void bubbleSort(vector<int> &vec) {
    for (int ix = 0; ix < vec.size(); ++ix) {
        for (int jx = ix + 1; jx < vec.size(); ++jx) {
            if (vec[ix] > vec[jx]) {
                swap(vec[ix], vec[jx]);
            }
        }
    }
}

int main() {
    int         ia[8] = {8, 32, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);
    cout << "vector before sort: " << endl;
    display(vec);
    bubbleSort(vec);
    cout << "vector after sort: " << endl;
    display(vec);
    return 0;
}


