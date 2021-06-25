/*************************************************************************
	> File Name: priority.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 May 2021 09:13:48 AM CST
 ************************************************************************/

#include<iostream>
#include <queue>
using namespace std;

int main() {
    
    priority_queue<int> p;
    
    priority_queue<int, vector<int>, greater<int>> que;
    
    p.push(3);
    p.push(5);

    que.push(3);
    que.push(5);

    cout << p.top() << endl;
    cout << que.top() << endl;
    

    return 0;
}
