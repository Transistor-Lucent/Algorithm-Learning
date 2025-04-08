// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	
	for (int i=2; i<=n; i++) {  // 构造dp数组 
		for (int j=1; j<=i; j++) {  // 遍历各值为根节点 
			dp[i] += dp[j-1] * dp[i-j];
		}
	}
	
	return dp[n];
}
	

int main() {
	int input = 5;
	cout << func(input) << endl;
	return 0;
}
