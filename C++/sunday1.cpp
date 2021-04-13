#include <iostream>

using namespace std;



int main()
{
    int len[128] = {0};
    string str1;
    string str2;
    cin >> str1 >> str2;
    int len2 = str2.size();
    int len1 = str1.size();
    for (int i = 0; i < 128; i++) len[i] = len2 + 1;
    for (int i = 0; i < len2; i++) len[str2[i]] = len2 - i; //zi fu zhong zui hou de yige zifu
    for (int i = 0, I = len1 - len2 + 1; i < I;  ) {
        int flag = 1;
        for (int j = 0; j < len2; j++ ) {
            if (str1[j] == str2[j]) continue;
            i += len[str1[i + len2]];
            flag = 0;
        }
        if (flag) return i;
    }
 
    return 0;
}

