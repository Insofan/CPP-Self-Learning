//
// Created by Insomnia on 2018/4/12.
//

#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    const int userNameSize = 10;
    string    userName;
    cout << "Please enter your name: ";
    cin >> setw(userNameSize) >> userName;
    cout << "\n";

    switch (userName.length()) {
        case 9:
            cout << "This is a very big name, indeed --"
                 << "we may have needed to shorten it !\n"
                 << "In any case, \n";
            break;
        default:
            cout << "Hello, " << userName
                 << " -- happy to make your acquaintance!\n";
    }


    return 0;
}
