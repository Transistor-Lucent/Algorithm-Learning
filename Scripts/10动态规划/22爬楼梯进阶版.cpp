// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n, int m) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	
	for (int j=1; j<=n; j++) {
		printf("j: %d\n", j);
		for (int i=1; i<=j && i<=m; i++) {  // i<=j是阶梯数要比步子大。i<=m是步子不能大于规定的步数 
			dp[j] += dp[j - i];
			pnt1d(dp, "dp");
		}
	}
	
	return dp[n];
}

int main() {
	int n = 3, m = 2;
	cout << func(n, m) << endl;
	return 0;
}
