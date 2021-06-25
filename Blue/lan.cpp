/*************************************************************************
	> File Name: lan.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 22 May 2021 07:15:58 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

bool Upletter(char ch) {
  return ch <= 'Z' && ch >= 'A';
}

void my_split(vector<string> &vec, string &str) {
  bool Upper = true;
  string temp = "";
  for (int i = 0; i < str.size(); i++) {
    if (Upletter(str[i]) && !Upper) {
      vec.push_back(temp);
      temp = "";
      temp += str[i];
      Upper = true;
    } else if (!Upletter(str[i])) {
      temp += str[i];
      Upper = false;
    } else if (Upletter(str[i]) && Upper) {
      temp += str[i];
      Upper = false;
    }
  }
    if (temp != "") vec.push_back(temp);
}

int main()
{
  string str1;
  string str2;
  vector<string> vec1;
  vector<string> vec2;
  int dp[1001][1001] = {0};

  cin >> str1;
  cin >> str2;

  my_split(vec1, str1);
  my_split(vec2, str2);

  int len1 = vec1.size();
  int len2 = vec2.size();
  
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (vec1[i - 1] == vec2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[len1][len2] << endl;
  return 0;
}
