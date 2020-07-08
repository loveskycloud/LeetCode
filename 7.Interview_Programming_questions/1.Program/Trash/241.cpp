#include <iostream>
using namespace std;
#define MAX_N 100000
typedef struct Pos{
    int x, y;
}Pos;
int main()
{   
    Pos a[MAX_N + 5];
    Pos b[MAX_N + 5];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i].x >> b[i].y;
    }


    
    return 0;
}

