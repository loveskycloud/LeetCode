#include <iostream>
#include <string.h>
using namespace std;

#define MAX_N 1000

char text[MAX_N + 5], pattern[MAX_N + 5];

int brute_force(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    for (int i = 0, I = len1 - len2 + 1;  i < I; i++)  {
        int j = 0; 
        for (; t[j]; j++) {
            if (t[j] == s[j + i]) continue;
            break;
        }
        if (!t[j]) return i;
    }
    return -1;
}

int sunday(char *s, char *t) {
    int ind[128] = {0};
    int len1 = strlen(s);
    int len = strlen(t);
    for (int i = 0; i < 128; i++) ind[i] = len + 1;
    for (int i = 0; t[i]; i++) ind[t[i]] = len - i;
    for (int i = 0, I = len1 - len + 1; i < I; ) {
        int flag = 1;
        for (int j = 0; j < len; j++ ) {
            if (t[j] == s[i + j]) continue;
            i += ind[s[i + len]];
            flag = 0;
            break;
        }
        if (flag) return i;
    }
    
    return -1;
}

int main()
{
    

    return 0;
}

