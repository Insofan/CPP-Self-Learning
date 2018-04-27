//
// Created by Insofan on 2018/4/25.
// MIT License
//

double factory(int n) {
    if (n != 1) {
        return (n-- * (n - 0.5));
    }
    return 1;
}