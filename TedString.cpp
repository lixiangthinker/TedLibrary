//
// Created by lixiang on 2024/11/17.
//

#include "TedString.h"

TedString::TedString(const char *c) {
    if (c != nullptr) {
        len = strlen(c);
        if (len > 10001) {
            len = 10000;
        }
        strncpy(a, c, len);
        a[len] = '\0';
    } else {
        a[0] = '\0';
        len = 0;
    }
}

int TedString::size() {
    return len;
}

int TedString::max_size() {
    return 10001;
}

std::ostream& operator<<(std::ostream& cout,TedString& tedString) {
    cout << tedString.c_str();
    return cout;
}

std::istream& operator>>(std::istream& cin,TedString& tedString) {
    tedString.len = 0;
    std::string temp;
    getline(cin,temp);
    strncpy(tedString.a,temp.c_str(),temp.size());
    tedString.len = temp.size();
    return cin;
}