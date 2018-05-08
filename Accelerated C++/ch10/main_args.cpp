//
// Created by Insomnia on 2018/5/8.
// MIT License
//

#include <iostream>

//argc 包含的元素个数, argv指向数组所包含的指针个数
int main(int argc, char *argv[]) {
    using namespace std;
    // if there are command-line arguments, write them
    cout << argc << endl;
    if (argc > 1) {
        cout << argv[1];               // write the first argument

        // write each remaining argument with a space before it
        for (int i = 2; i != argc; ++i)
            cout << " " << argv[i];    // `argv[i]' is a `char*'
    }
    cout << endl;

    return 0;
}


