// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int cal(vector<int> value, int l, int h) {
	int n = h - l + 1;
	if (n == 0) return 0;
	if (n == 1) return value[l];
	
	vector<int> dp(value.size(), 0);  // 注意不是dp(n, 0) 
	dp[l] = value[l];
	dp[l + 1] = max(value[l], value[l + 1]);
	for (int i=l+2; i<=h; i++) {
		dp[i] = max(dp[i-2] + value[i], dp[i-1]);
	}
	
	return dp[h];
}

int func(vector<int> value) {
	if (value.size() == 0) return 0;
	if (value.size() == 1) return value[0];
	
	int n = value.size();
	int res1 = cal(value, 0, n - 2);  // 因为到dp[i-2]时不能直接比较dp[0]，所以到两种情况分开算 
	int res2 = cal(value, 1, n - 1);
	
	return max(res1, res2);
}

int main() {
	int a[] = {2, 3, 2}, n = 3;
	vector<int> nums(a, a + n);
	cout << func(nums) << endl;
	return 0;
}
