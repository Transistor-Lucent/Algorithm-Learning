// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> weight, vector<int> value, vector<int> nums, int bw) {
	int n = weight.size();
	vector<int> dp(bw + 1, 0);
	
	for (int i=0; i<n; i++) {
		for (int j=bw; j>=weight[i]; j--) {
			for (int k=1; k <= nums[i] && j >= (k * weight[i]); k++) {  // 看能物品i能装进多少个
				dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]); 
//				printf("k: %d, nums[i]: %d, j: %d\n", k, nums[i], j);
//				pnt1d(dp, "dp");
			}
		}
	}
	
	return dp[bw];
}

int main() {
	int w[] = {1, 3, 4}, n = 3;
	int v[] = {15, 20, 30};
	int nm[] = {2, 3, 2};
	
	vector<int> weight(w, w + n), value(v, v + n), nums(nm, nm + 3);
	int bw = 10;
	cout << func2(weight, value, nums, bw) << endl;
	return 0;
}
