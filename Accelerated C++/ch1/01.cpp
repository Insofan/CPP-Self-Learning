//
// Created by Insofan on 2018/4/15.
// MIT License
//

#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello, " + name + '!';

    //第二行第四行
    const std::string spaces(greeting.size(), ' ');
    const std::string second   = "* " + spaces + " *";

    //输出第一行和第五行
    const std::string first(second.size(), '*');

    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    return 0;
}


