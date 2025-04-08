// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<string> s, int m, int n) {
	vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
	pnt2d(dp, "dp");
	
	for (int k=0; k<s.size(); k++) {  // 每一个s[k]单独遍历一边dp数组 
		int onen = 0, zeron = 0;
		for (int l=0; l<s[k].length(); l++) {
			if (s[k][l] == '0') zeron++;
			else onen++;
		}
		
		for (int j=n; j>=onen; j--) {
			for (int i=m; i>=zeron; i--) {
				printf("i: %d, j: %d\n", i, j);
				dp[i][j] = max(dp[i][j], dp[i-zeron][j-onen] + 1);
			}
		}
		pnt2d(dp, "dp");
	}
	
	return dp[m][n];
}

int main() {
	string s[] = {"10", "0001", "111001", "1", "0"};
	int len = 5;
	vector<string> strs;
	int m = 5, n = 3;
	for (int i=0; i<len; i++) {
		strs.push_back(s[i]);
	}
	cout << func(strs, m, n) << endl;
	return 0;
}
