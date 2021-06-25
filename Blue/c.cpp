/*************************************************************************
	> File Name: c.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 May 2021 12:06:26 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[100];
int book[100];
int cnt;
int num[100];
int n;
void dfs(int left) {
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (book[i] == 0) {
            book[i] = 1;
            num[cnt++] = i;
            dfs(left - 1);
            cnt--;
            book[i] = 0;
        }
    }
}

int main() {
    cin >> n;    
    dfs(n);

    return 0;
}
