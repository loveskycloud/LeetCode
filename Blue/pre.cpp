/*************************************************************************
	> File Name: pre.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 11:17:46 AM CST
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

int pre[26];
int pre_in[26];
int back[10010];
int back_in[10010];
char str[10010];


int main() {
    scanf("%s", str);
    int len = strlen(str);

    for (int i = 0; i < 26; i++) {
        pre[i] = -1;
        back_in[i] = len;
    }

    for (int i = 0; i < len; i++) {
        back[i] = len;
    }

    for (int i = len - 1; i >= 0; i--) {
       back[i] = back_in[str[i] - 'a'];
       back_in[str[i] - 'a'] = i;
    }
    
    int ans = 0;

    for (int i = 0; i < len; i++) {
       ans += (i - pre[str[i] - 'a']) * (back[i] - i);
       pre[str[i] - 'a'] = i; 
    }
    
    cout << ans << endl;
    return 0;
}

