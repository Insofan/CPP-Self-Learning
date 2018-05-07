//
// Created by Insomnia on 2018/5/7.
// MIT License
//

#include <iostream>

int next(int n) {
    return n + 1;

}

int main() {
    using namespace std;

    //说明我们对fp解引用, 并且使用一个int函数来调用它的话, 就会产生int类型的结果, 这条语句暗示了fp是一个函数指针.
    //fp function_pointer函数指针
    int (*fp)(int);
    //下面两个操作是一样的
    fp = &next;
//    fp = next;
    //下面两个操作是一样的
//    int i = (*fp)(3);
    int i = fp(5);
    cout << i;

    return 0;
}


