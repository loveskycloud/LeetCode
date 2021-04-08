#include <iostream>
using namespace std;

int expand(string s, int left, int right) {
    int l = left;
    int r = right;
    while (s[l] && s[r] && s[l] == s[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}

string findLongest(string s) {
    if (s == "" || s.length() < 1) return "";
    int start = 0;
    int end = 0;
    int len = 0; //max len 
    for (int i = 0; i < s.length(); i++) {
        int len1 = expand(s, i, i);
        int len2 = expand(s, i, i + 1);
        len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2; // zhen dui ji ou you hua
            end = i + len / 2;
        }
    }
    return s.substr(start, end - start + 1);
}

int main()
{
    string str;
    cin >> str;
    cout << findLongest(str) << endl;
    return 0;
}

