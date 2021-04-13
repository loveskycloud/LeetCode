#include <iostream>

using namespace std;

int main()
{

    int a, b;
    cin >> a;
    cin >> b;
    int temp = a;
    int tempb = b;
    while (temp) {
        (temp & 1 ) ? printf("%d", 1) : printf("%d", 0);
        temp = temp >> 1;
    }
    printf("\n");
    while (tempb) {
        (tempb & 1 ) ? printf("%d", 1) : printf("%d", 0);
        tempb = tempb >> 1;
    }
    printf("\n");

    cout << (a | b) << endl;
    return 0;
}

