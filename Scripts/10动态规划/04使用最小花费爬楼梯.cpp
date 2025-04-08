// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> cost) {
	vector<int> dp(cost.size() + 1);
	dp[0] = 0;
	dp[1] = 0;
	
	for (int i=2; i<dp.size(); i++) {
		dp[i] = mini(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
	}
	
	return dp[dp.size() - 1];
}
	

int main() {
	int cost[] = {10, 15, 20}, n = 3;
	vector<int> input(cost, cost + n);
	cout << func(input) << endl;
	return 0;
}
