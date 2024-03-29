#include <iostream>
#include <string.h>

#define maxn 1000

int ind[512] = {0};


int sunday(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0; i < 512; i++) ind[i] = len2 + 1; 
    for (int i = 0; i < len2; i++) ind[t[i]] = len2 - i;
    for (int i = 0, I = len1 - len2 + 1; i < I;) {
        int flag = 1;
        for (int j = 0; j < len2; j++) {
            if (t[j] == s[j + i]) continue;
            i += ind[s[i + len2]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    return -1;
}


int main()
{
    char str[] = "123456";
    char pattern[] = "456";
    std::cout << str << std::endl;
    std::cout << pattern << std::endl;
    std::cout << sunday(str, pattern) << std::endl;
    return 0;
}

