//
// Created by jbd on 02/10/2025.
// © 2025 Jeremia Sell. All rights reserved.
//

#ifndef API_JBI_H
#define API_JBI_H
#include <iostream>
#include <string>

using namespace std;

string reverb_s(string input) {
    string final;
    for (int i = input.length() - 1; i >= 0; i--) {
        final.push_back(input.at(i));
    }
    return final;
}

bool startswith(string beta1, string beta2) {
    int count = 0;
    for (int i = 0 ; i < beta2.length(); i++) {
        if (beta2.at(i) == beta1.at(i)) {
            count++;
        }
    }
    if (count == beta2.length()) {
        return true;
    }
}

#endif //API_JBI_H