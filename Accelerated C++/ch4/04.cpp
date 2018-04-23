//
// Created by Insofan on 2018/4/20.
// MIT License
//

#include <istream>
#include <iomanip>
#include <iostream>
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
using std::domain_error;
using std::istream;

/*注意, 这里有两个函数是同一个名字, cpp中可以出现几个函数有同一个名字, 这种概念叫重载*/
double grade(double midtern, double final, const vector<double> &hw);

double grade(double midtern, double final, double homework);

double median(vector<double> vec);

istream &readHw(istream &in, vector<double> &hw);

int main() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midtern, final;
    cin >> midtern >> final;

    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    int    count = 0;
    double sum   = 0;

    double         x;
    vector<double> homework;

    readHw(cin, homework);

    //如果报错用下面的catch
    try {
        double     finalGrade = grade(midtern, final, homework);
        streamsize prec       = cout.precision();
//        cout << "Your final grade is " << setprecision(4)
//             << finalGrade
//             << setprecision(prec) << endl;
        cout << "Your final grade is " << setprecision(4)
             << grade(midtern, final, homework)
             << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl << "You must enter your grades. "
                        "Please try again." << endl;
    }

    return 0;
}

double grade(double midtern, double final, const vector<double> &hw) {
//    return 0.2 * midtern + 0.4 * final + 0.4 * median(hw);
    return grade(midtern, final, median(hw));
}

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

istream &readHw(istream &in, vector<double> &hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x) {
            hw.push_back(x);
            in.clear();
        }
    }
    return in;
}


double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;
    vec_sz                            size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

