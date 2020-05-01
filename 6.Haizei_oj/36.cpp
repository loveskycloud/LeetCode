#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int val;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        sum += val;
    }
    cout << sum << endl;
    return 0;
}

