#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main()
{   
    int n, k, id;
    cin >> n >> k >> id;
    if (n == k) {
        cout << "1/1" << endl;
    } else if (k == 0) {
        cout << "0/1" << endl;
    } else {
        int t = gcd(n, k);
        cout << k / t << "/" << n / t << endl;
    }
     
    return 0;
}

