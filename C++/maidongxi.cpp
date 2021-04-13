#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100005

int person[maxn];
int goods[maxn];
int book[maxn];

int n, m;


int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> person[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> goods[i];
    }

    sort(person, person + n);
    sort(goods, goods + m);
    
    for (int i = 0; i < n; i++) {
        cout << person[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < m; j++) {
        cout << goods[j] <<  " ";
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = m;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (goods[mid] >= person[i] && book[mid] == 0) {
                r = mid - 1; 
            } else if (goods[mid] > person[i] || book[mid] == 1){
                l = mid;
            }
        }
        cout << l << endl;
        if (l < 0 || l >= m) {
            continue;
        }
        cout << "person : " << i <<  " : " << person[i] <<  "goods : " << l << " : " << goods[l] << endl;  
        sum++;
        book[l] = 1;

    }
    cout << sum << endl;

    return 0;
}

