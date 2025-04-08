// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

// dp[i][0]: 到第i天持有股票时剩的钱 
// dp[i][1]: 到第i天不持有股票时累积赚到的钱 
int func(vector<int> prices) {
	int n = prices.size();
	vector<vector<int> > dp(n, vector<int>(2, 0));
	dp[0][0] = -prices[0];
	dp[0][1] = 0;
	
	for (int i=1; i<n; i++) {
		dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);  // max(今天不买, 今天买) 
		dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);  // max(今天不卖, 今天卖)
	}
	
	return dp[n-1][1];
}

int main() {
	int a[] = {7, 1, 5, 3, 6, 4}, n = 6;
	vector<int> input(a, a + n);
	cout << func(input) << endl;
	return 0;
}
