//
// Created by Insofan on 2018/5/1.
// MIT License
//

#include <iostream>
using namespace std;

void staticLocalVar()
{
    static int a = 0; // 运行期时初始化一次, 下次再调用时, 不进行初始化工作
    cout << a << endl;
    a++;
}
int main()
{
    staticLocalVar(); // 第一次调用, 输出a=0
    staticLocalVar(); // 第二次调用, 记忆了第一次退出时的值, 输出a=1
    return 0;
}


