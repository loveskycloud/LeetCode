/*************************************************************************
	> File Name: strsplit.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 10:44:55 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int lc[26];
int rc[26];
int r[10010];

int main() {
    cin.tie(0);

    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < 26; i++) {
        lc[i] = -1;
        rc[i] = len;
    }
    
    for (int i = 0; i < len; i++) {
        r[i] = len;
    }

    for (int i = len - 1; i >= 0; i--) {
        r[i] = rc[s[i] - 'a'];
        rc[s[i] - 'a'] = i;
    }
    
    int ans = 0;

    for (int i = 0; i < len; i++) {
        ans += (i - lc[s[i] - 'a']) * (r[i] - i);
        lc[s[i] - 'a'] = i;
    }

    cout << ans << endl;

    return 0;
}
