// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n) {
	vector<int> dp(n + 1, 0);
	dp[2] = 1;
	
	for (int i=3; i<=n; i++) {
		for (int j=1; j<=i/2; j++) {  // 相当于遍历分割线 
			dp[i] = max(dp[i], max((i-j) * j, dp[i-j] * j));  // max的参数中有dp[i]，相当于与当前i的其他分割方式比较 
		}
	}
	
	return dp[n];
}

int main() {
	int input = 10;
	cout << func(input) << endl;
	return 0;
}
