// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

#define maxint 0x7fffffff

int func(int n) {
	vector<int> dp(n + 1, maxint);
	
	dp[0] = 0;
	for (int i=0; i * i <= n; i++) {
		for (int j=i*i; j<=n; j++) {
			if (dp[j - i*i] != maxint) dp[j] = min(dp[j-i*i] + 1, dp[j]);  // i++后，加入i和不加入i的对比 
		}
	}
	
	return dp[n];
}
		

int main() {
	int n = 12;
	cout << func(n) << endl;
	return 0;
}
