// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> input, int target) {
	int sum = 0, n = input.size();
	for (int i=0; i<n; i++) {
		sum += input[i];
	}
	if (abs(target) > sum) return 0;  // 注意这种情况 
	if ((sum + target) % 2 == 1) return 0;  // 加法和为x时，有x-(sum-x)==target，移项得x=(target+sum)/2 
	int pos_sum = (sum + target) / 2;
	
	vector<int> dp(pos_sum+1, 0);  
	// 初始时令容量为0、只考虑物品[0]时，只有不放入任何物品一种放法。若input[0]为0，则遍历到i=0、j=0时，dp[0]的值由`dp[j] += dp[j - input[i]];`变为2，即增加了放入input[0]这一种放法
	dp[0] = 1;  // 若使用二维dp，则初始化时，第一列的值是重量为0物品的排列组合数量；第一行的dp[0][>=1]中，重量等同input[0]重量的地方为1，即有放入input[0]这一种放法 
	for (int i=0; i<n; i++) {
		for (int j=pos_sum; j>=input[i]; j--) {  // 倒序保证每个数只用一次 
			dp[j] += dp[j - input[i]];  // dp[j]是当前容量下不放input[i]的放法，dp[j-input[i]]是减去input[i]重量后的放法，减去的input[i]这部分只有放一个input[i]这一种方法
		}
	}
			
	return dp[pos_sum];
}

int main() {
	int a[] = {100}, n = 1, target = -200;
	vector<int> input(a, a + n);
	cout << func(input, target) << endl;
	return 0;
}
