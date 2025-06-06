// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> prices) {
	int n = prices.size();
	vector<vector<int> > dp(n, vector<int>(5, 0));
	dp[0][1] = -prices[0];
	dp[0][3] = -prices[0];
	
	for (int i=1; i<n; i++) {
		dp[i][1] = max(dp[i-1][1], -prices[i]);
		dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
		dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
		dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
	}
	
	return dp[n-1][4];
}

int main() {
	int a[] = {3, 3, 5, 0, 0, 3, 1, 4}, n = 8;
	vector<int> input(a, a + n);
	cout << func(input) << endl;
	return 0;
}
