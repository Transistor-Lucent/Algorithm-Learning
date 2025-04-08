// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

bool func(vector<int> input) {
	int n = input.size(), sum = 0;
	for (int i=0; i<n; i++) {
		sum += input[i];
	}
	int target;
	if (sum % 2 == 1) return false;
	else target = sum / 2;
	
	vector<int> dp(target + 1, 0);
	pnt1d(dp, "dp");
	for (int i=0; i<n; i++) {
		for (int j=target; j>=input[i]; j--) {
			dp[j] = max(dp[j], dp[j-input[i]] + input[i]);
		}
	}
	pnt1d(dp, "dp");
	
	return dp[target] = target;
}
	

int main() {
	int a[] = {1, 5, 11, 5}, n = 4;
	vector<int> input(a, a + n);
	cout << func(input) << endl;
	return 0;
}
