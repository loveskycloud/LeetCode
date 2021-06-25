/*************************************************************************
	> File Name: quanpailie.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 May 2021 11:25:16 AM CST
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;


vector<int> vec;
vector<int> book;
vector<vector<int>> ans;
vector<int> temp;
int n;

void dfs(int left) {
    if (left == 0) {
        ans.push_back(temp);
        temp.clear();
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (book[i] == 0) {
            book[i] = 1;
            temp.push_back(vec[i]);
            dfs(left - 1);
            book[i] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    book.resize(n + 1, 0);
    dfs(n);

    return 0;
}
