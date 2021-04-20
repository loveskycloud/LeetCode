#include <iostream>
#include <algorithm>
using namespace std;

string change(int n, int k) {
    int ans = 0, left;
    string temp = "";
    while (n) {
        temp += n % k + 48;
        n = n / k;
    }
    string str;
    for (int i = temp.size() - 1; i >= 0; i--) {
        str += temp[i];
    }
    return str;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << change(n, k) << endl;
    return 0;
}

