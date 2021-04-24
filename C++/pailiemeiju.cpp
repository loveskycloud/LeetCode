#include <iostream>

using namespace std;

string str;
string temp;
int n;
bool book[1000];
int cnt;

void func(int left) {
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++) {
        if (book[i] == false) {
            book[i] = true;
            temp[cnt++] = str[i];
            func(left - 1);
            book[i] = false;
            cnt--;
        }
    }
}

int main()
{
    cin >> n;
    cin >> str;
    func(n);
    return 0;
}

