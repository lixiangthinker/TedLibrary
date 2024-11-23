//
// Created by lixiang on 2024/11/17.
//

#ifndef TEDLIBRARY_TEDSTRING_H
#define TEDLIBRARY_TEDSTRING_H
#include <cstring>
#include <iostream>

class TedString {
private:
    char a[10001];
    int len;
public:
    TedString(const char* c);
    int size();
    int max_size();
    friend std::ostream& operator<<(std::ostream& cout,TedString& tedString);
    friend std::istream& operator>>(std::istream& cin,TedString& tedString);

    inline const char* c_str() const{
        return this->a;
    }

    inline char operator[](int i) {
        return a[i];
    }

    inline TedString& operator+(char c) {
        a[len] = c;
        len++;
        a[len] = '\0';
        return *this;
    }

    inline TedString& operator+(const char* c) {
        strcat(a,c);
        len += strlen(c);
        a[len] = '\0';
        return *this;
    }

    inline bool operator==(const TedString& right) {
        return strcmp(this->a, right.a) == 0;
    }

    inline bool compare(const TedString& right) {
        return operator==(right);
    }

    inline TedString& push_back(char c) {
        return operator+(c);
    }

    inline TedString& pop_back() {
        len--;
        a[len] = '\0';
        return *this;
    }

    inline TedString& clear() {
        len = 0;
        a[len] = '\0';
        return *this;
    }
};

#endif //TEDLIBRARY_TEDSTRING_H
