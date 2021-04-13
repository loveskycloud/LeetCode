#include <iostream>
#include <string.h>

using namespace std;

void my_memcpy(void *dst, void *src, size_t size) {
    if (dst == NULL || src == NULL) return ;
    char *pdst;
    char *psrc;
    if (src < dst && (char *)src + size > (char *)dst) {
        pdst = (char *)dst + size - 1;
        psrc = (char *)src + size - 1;
        while (size--) {
            *pdst-- = *psrc--;
        }
    } else {
        pdst = (char *)dst;
        psrc = (char *)src;
        while (size--) {
            *pdst++ = *psrc++;
        }
    }
    return ;
}

union node {
    int a;
    char b;
};

int main()
{


    char arr[] = "abcde";
    char brr[3];
    char crr[1];
    int d;

    int *a = new int(0);
    int *b = new int(0);




    memcpy(brr, arr, sizeof(3));
    cout << sizeof(3) << endl;
    cout << strlen(brr) << endl;
    cout << brr << endl;
    cout << arr[0] << endl;
    cout << &arr << endl;
    cout << &brr << endl;
    cout << &crr << endl;
    cout << &d << endl;


    cout << a << endl;
    cout << b << endl;

    node c;
    c.b = 1;
    int t = 31;
    cout << ((c.b >> t) & 1) << endl;
    cout << (c.a & (0x7fffffff + 1)) << endl;

    return 0;
}

