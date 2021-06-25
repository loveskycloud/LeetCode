/*************************************************************************
	> File Name: mdfs.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 10:42:12 PM CST
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
 
const int N = 5;
int g[N][N];
//上右下左
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans;
 
void dfs(int r, int l,int cnt)
{
	if (cnt == 16)
	{
		ans++;
		return;
	}
	
	g[r][l] = cnt;
	for (int i = 0; i < 4; i++)
	{
		int x = dx[i] + r, y = dy[i] + l;
		if (x < 4 && x >= 0 && y < 4 && y >= 0 && g[x][y] == 0)
			dfs(x, y, cnt + 1);
	}
	g[r][l] = 0;//恢复现场
}
int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			dfs(i, j, 1);  //每个位置都可能放1去搜有多少中方案
 
	cout << ans << endl;
	system("pause");
	return 0;
}
