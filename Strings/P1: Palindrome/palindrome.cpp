#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

int main() {
    char a = 'a';
    char comma = ',';

    if (isalnum(a)) {
        cout << "soy alphanumeric" << endl;
    }

    return 0;
}