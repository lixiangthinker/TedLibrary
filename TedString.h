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
    TedString(const char* c) {
        if (c != nullptr) {
          len = strlen(c);
          if (len > 10001) {
              len = 10000;
          }
          strncpy(a,c,len);
          a[len] = '\0';
        } else {
          a[0] = '\0';
          len = 0;
        }
    }
    int size() {
        return len;
    }

    int max_size() {
        return 10001;
    }
    const char* c_str() const{
        return this->a;
    }

    char operator[](int i) {
        return a[i];
    }

    TedString& operator+(char c) {
        a[len] = c;
        len++;
        a[len] = '\0';
        return *this;
    }

    TedString& operator+(const char* c) {
        strcat(a,c);
        len += strlen(c);
        a[len] = '\0';
        return *this;
    }

    bool operator==(const TedString& right) {
        return strcmp(this->a, right.a) == 0;
    }

    bool compare(const TedString& right) {
        return operator==(right);
    }

    TedString& push_back(char c) {
        return operator+(c);
    }

    TedString& pop_back() {
        len--;
        a[len] = '\0';
        return *this;
    }

    TedString& clear() {
        len = 0;
        a[len] = '\0';
        return *this;
    }
};

// 定义全局的 operator<< 函数
std::ostream& operator<<(std::ostream& os, const TedString& str) {
    os << str.c_str(); // 直接访问 MyString 的私有成员 data
    return os;
}

#endif //TEDLIBRARY_TEDSTRING_H
