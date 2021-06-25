/*************************************************************************
	> File Name: dfs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 10:29:54 PM CST
 ************************************************************************/

#include<iostream>
#include <string.h>
using namespace std;

int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int book[5][5];
int arr[5][5];
int ans = 0;

void dfs(int x, int y, int len) {
    if (len == 16) {
        ans++;
        return ;
    }
    book[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int rx = x + dir[i][0];
        int ry = y + dir[i][1];
        if (rx < 0 || rx >= 4 || ry < 0 || ry >= 4) continue;

        //if (rx >= 0 && rx < 4 && ry < 4 && ry >= 0 && book[rx][ry] == 0) 
        if (book[rx][ry] == 0)
        dfs(rx, ry, len + 1);
    }
    book[x][y] = 0;
}

int main() {
    memset(book, 0, sizeof(book));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            dfs(i,j, 1);
        }
    }

    cout << ans << endl;

    return 0;
}

