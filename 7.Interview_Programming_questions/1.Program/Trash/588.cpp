#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define MAX_N 10000000
int ans[31][100005] = {{}, {1}}, n;

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int ind = 0;
        for (int j = 0; ans[i - 1][j] != 0; j++) {
            int x = 1;
            while (ans[i - 1][j] == ans[i - 1][j + 1]) {
                x++;
                j++;
            }
            ans[i][ind++] = x;
            ans[i][ind++] = ans[i - 1][j];
        }
    }
    for (int i = 0; ans[n][i] != 0; i++) {
        cout << ans[n][i];
    }
    cout << endl;
    return 0;
}

