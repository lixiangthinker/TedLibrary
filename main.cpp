#include <iostream>
#include "TedString.h"
#include <string>
using namespace std;
int main() {
    TedString t = "hello world!";
    TedString t2 = "hello world!";
    t.clear();
    cout << t;
    return 0;
}
