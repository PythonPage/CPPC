//
// Created by jbd on 02/10/2025.
// © 2025 Jeremia Sell. All rights reserved.
//

#ifndef API_JBI_H
#define API_JBI_H
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string reverb_s(string input) {
    string final;
    for (int i = input.length() - 1; i >= 0; i--) {
        final.push_back(input.at(i));
    }
    return final;
}



#endif //API_JBI_H