#include <iostream>

using namespace std;

class Solution {
    public :
        bool func(int *arr) {
            return recur(arr, 0, n - 1);
        }

        bool recur(int *arr, int start, int end) {
            if (start >= end) return true;
            int p = start;
            while (p < end) p++;
            int m = p;
            while (p > j) p++;
            
            return p == j && recur(, start, m - 1), recur(, m, j - 1); // zuo zi shu you zi shu
        }
};

int main()
{
    return 0;
}

