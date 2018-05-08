//
// Created by Insomnia on 2018/5/8.
// MIT License
//

#include <iostream>
#include <cstddef>

using namespace std;

int main() {
    const size_t NDim = 3;
    double coords[NDim];
    const int month_lengths[] = {
            31, 28, 31,
            31, 31, 30,
    };

    const char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    size_t strlen(const char* p) {
        size_t size = 0;
        while (*p++ != '\0'){
            ++size;
        }
        return size;
    }

    return 0;
}


