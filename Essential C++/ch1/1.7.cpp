//
// Created by Insomnia on 2018/4/12.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string fileName;
//    cout << "Please input file name (input.txt or text.txt) " << endl;
//    cin >> fileName;
//    ifstream readFile(fileName);
    ifstream readFile("text.txt");
    if (!readFile.is_open()) {
        cerr << "oops! unable to open input file\n";
        return -1;
    }
    cout << "bingo" << endl;
    string word;
    vector<string> vecWord;
    while (readFile >> word) {
        vecWord.push_back(word);
    }
    cout << "Original text: ";
    for (vector<string>::iterator itr = vecWord.begin(), vecEnd = vecWord.end(); itr != vecEnd; ++itr) {
        cout << *itr << " ";
    }

    return 0;
}
