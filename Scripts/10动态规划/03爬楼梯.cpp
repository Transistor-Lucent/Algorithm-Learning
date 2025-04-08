// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n) {
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i=3; i<=n; i++) {
		// dp[i-2]和dp[i-1]到dp[i]各有一种方法。注意是分布乘法，所以是dp[i-2]*1 + dp[i-1]*1，而不是(dp[i-2] + 1) + (dp[i-1] + 1)。
		// 又注意dp[i-2]到dp[i]可走一个两步或走两个一步，后者算在dp[i-1]到dp[i]中，所以递推公式里dp[i-2]到dp[i]只算一种走法 
		dp[i] = dp[i-2] + dp[i-1]; 
	}
	
	return dp[n];
}

int main() {
	int stair = 5;
	cout << func(stair) << endl;
	return 0;
}
