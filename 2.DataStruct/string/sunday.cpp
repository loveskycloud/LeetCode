#include <iostream>

using namespace std;

int sunday(string s, string t) {
    int len1 = s.size();
    int len2 = t.size();
    int ind[128];
    for (int i = 0; i < 128; i++) ind[i] = len2 + 1;
    for (int i = 0; i < len2; i++) ind[t[i]] = len2 - i;
    for (int i = 0, I = len1 - len2 + 1; i < I; ) {
        int flag = 1;
        for (int j = 0; j < len2; j++) {
            if (s[j + i] == t[j]) continue;
            i += ind[s[len2 + i]];
            flag = 0;
        }
        if (flag) return i;
    }
    return -1;
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << sunday(str1, str2) << endl;

    return 0;
}

