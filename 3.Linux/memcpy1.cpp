#include <iostream>

using namespace std;

void my_memcpy(void *dst, const void *src, size_t size) {
    if (dst == NULL || src == NULL) return ;
    char *pdst;
    char *psrc;
    if (psrc < pdst && (char *)psrc + size > (char *)pdst) {
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

int main()
{
    char arr[] = "1234";
    char brr[5];
    my_memcpy(brr, arr, sizeof(arr));
    cout << brr << endl;
    return 0;
}

