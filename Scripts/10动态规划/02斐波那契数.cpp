// 随想录
#include <iostream>
#include <vector>
#include "utility.h"  //<> 表示从系统目录下开始搜索，然后再搜索PATH环境变量所列出的目录，不搜索当前目录。"" 表示从当前目录开始搜索，然后是系统目录和PATH环境变量所列出的目录。

using namespace std;

// 动规法 
int func(int n) {
	vector<int> dp(2);
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i=2; i<=n; i++) {
		dp.push_back(dp[i-1] + dp[i-2]);
		pnt1d(dp);
	}
	
	return dp[n];
}

// 空间优化
int func_memOpt(int n) {
	vector<int> dp(2);
	dp[0] = 0;
	dp[1] = 1;
	int sum = 0; 
	
	for (int i=2; i<=n; i++) {
		sum = dp[0] + dp[1];
		dp[0] = dp[1];
		dp[1] = sum;
		pnt1d(dp, "mem opt");
	}
	
	return dp[1];
}

int main() {
	int n = 10;
	cout << func_memOpt(n) << endl;
	return 0;
}
