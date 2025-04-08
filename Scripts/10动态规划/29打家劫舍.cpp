// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> value) {
	int n = value.size();
	if (n == 0) return 0;
	if (n == 1) return value[0];
	
	vector<int> dp(n, 0);
	dp[0] = value[0];
	dp[1] = max(value[0], value[1]);
	
	for (int i=2; i<n; i++) {
		dp[i] = max(dp[i-2] + value[i], dp[i-1]);
	}
	
	return dp[n - 1];
}

int main() {
	return 0;
}
