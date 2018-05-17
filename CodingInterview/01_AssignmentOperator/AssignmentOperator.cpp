//
// Created by Insomnia on 2018/5/17.
// MIT License
//
//==================================================================

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
#include <iostream>
#include <cstring>
#include <cstdio>

class CMyString {
public:
    CMyString(char *pData = nullptr);

    CMyString(const CMyString &str);

    CMyString &operator=(const CMyString &str);

    // 函数前加 ~ 是析构函数, 析构函数名也应与类名相同，只是在函数名前面加一个位取反符~，例如~stud( )，以区别于构造函数。它不能带任何参数，也没有返回值（包括void类型）
    ~CMyString();

private:
    char *m_pData;
};

CMyString &CMyString::operator=(const CMyString &str) {
    if (this != &str) {

    }
    return *this;
}

int main() {
    using namespace std;

    return 0;
}


