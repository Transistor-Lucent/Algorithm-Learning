// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

// dp[i][0]: ����i��������������ٵ�
// dp[i][1]: ����i��������׬������ 
int func(vector<int> prices) {
	int n = prices.size();
	if (n == 0) return 0;
	
	vector<vector<int> > dp(n, vector<int>(2, 0));
	dp[0][0] -= prices[0];
	dp[0][1] = 0;
	for (int i=1; i<n; i++) {
		dp[i][0] = max(dp[i-1][0], -1 * prices[i]);
		dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
	}
	
	return dp[n-1][1];
}

int main() {
	int a[] = {7, 1, 5, 3, 6, 4}, n = 6;
	vector<int> input(a, a + n);
	cout << func(input) << endl;
	return 0;
}
