#include <iostream>

using namespace std;

string expandtoodd(string s) {

    string Str = "*#";
    for (int i = 0; i < s.size(); i++) {
        Str += s[i];
        Str += '#';
    }

    return Str;
}

string Manacher(string s) {

    string s1 = expandtoodd(s);
    int idd = 0, max = 0, Len[1000], maxlen = 0, start = 0;
    for (int i = 0; i < s1.length(); i++) {
        if (i < max) Len[i] = min(Len[2 * idd - i], max - i);
        else Len[i] = 1;
        for ( ; s1[i + Len[i]] == s1[i - Len[i]] && i + Len[i] < s1.size() && i - Len[i] > 0; Len[i]++);
        if (Len[i] + i > max) {
            max = Len[i] + i;
            idd = i;
        }
        if (Len[i] - 1 > maxlen) {
            maxlen = Len[i] - 1;
            start = (idd - maxlen) / 2;
        }
    }

    return s.substr(start, maxlen);
}

int main()
{
    return 0;
}

