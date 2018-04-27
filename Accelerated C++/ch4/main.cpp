//
// Created by Insomnia on 2018/4/26.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include "median.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::domain_error;
using std::streamsize;
using std::string;
using std::max;
using std::vector;

int main() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    //输入家庭作业, 直到文件结束标志, 按z键或者d键, 注意这里可以用两个"", 可以自动连接成一句话
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    int count = 0;
    double sum = 0;
    double x;
    vector<double> homework;
    while (cin >> x) {
        homework.push_back(x);
        ++count;
        sum += x;
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
        return -1;
    }
    sort(homework.begin(), homework.end());
    vec_sz mid = size / 2;
//    double median;
//    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

    //write the result
    streamsize prec = cout.precision();
    //setprecision 是一个控制符, 它控制流, 使得后来的输出以给定位数的有效数字显示, 我们通常要求系统用三位有效数字来输出成绩,实际上就是控制一共显示多少位,
    //同一个表达式中同时出现普通的整数和无符号类型的整数,  普通的整数就会换成无符号类型
    cout << "Your final grade is " << setprecision(4)
         << 0.2 * midterm + 0.4 * final + 0.4 * median(homework)
         << setprecision(prec) << endl;
    return 0;
}
