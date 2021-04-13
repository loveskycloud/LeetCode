#include <iostream>
#include <string.h>
using namespace std;

int shift_and(char *s, char *t) {
    int code[128] = {0};
    int len = 0;
    for (len = 0; t[len]; len++) {
        code[t[len]] |= (1 << len);
    } 
    int p = 0;
    for (int i = 0; s[i]; i++) {
        p = (p << 1 | 1) & code[s[i]];
        if (p & (1 << (len - 1))) return i - len + 1;
    }

    return -1;
}

int main() {
    char str[] = "123455";
    char pattern[] = "455";
    cout << shift_and(str, pattern) << endl;
    return 0;
}

