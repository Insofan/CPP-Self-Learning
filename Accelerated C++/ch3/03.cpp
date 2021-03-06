//
// Created by Insofan on 2018/4/19.
// MIT License
//

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
//表示长度
using std::streamsize;
using std::vector;
using std::sort;

int main() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    //ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    //ask for the homework grades
    //输入家庭作业, 直到文件结束标志, 按z键或者d键, 注意这里可以用两个"", 可以自动连接成一句话
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    //the number and sum of grades read so far
    int    count = 0;
    double sum   = 0;

    //a variable into which to read
    double         x;
    //invariant:
    //we have read count grades so far, and sum is the sum of the first count grades
    /*cin 类型istream */
    vector<double> homework;
    while (cin >> x) {
        homework.push_back(x);
        ++count;
        sum += x;
    }
    //vector类型定义了一个类型, 名叫vector<double>::size_type, 还定义了一个名叫size 的函数
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
        return -1;
    }
    sort(homework.begin(), homework.end());
    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

    //write the result
    streamsize prec = cout.precision();
    //setprecision 是一个控制符, 它控制流, 使得后来的输出以给定位数的有效数字显示, 我们通常要求系统用三位有效数字来输出成绩,实际上就是控制一共显示多少位,
    //同一个表达式中同时出现普通的整数和无符号类型的整数,  普通的整数就会换成无符号类型
    cout << "Your final grade is " << setprecision(4)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;
    return 0;
}


