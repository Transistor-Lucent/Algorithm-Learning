// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> input) {
	int n = input.size();
	int sum = 0;
	for (int i=0; i<n; i++) {
		sum += input[i];
	}
	int target = sum / 2;
	
	vector<int> dp(target + 1, 0);
	for (int i=0; i<n; i++) {
		for (int j=target; j>=input[i]; j--) {
			dp[j] = max(dp[j], dp[j-input[i]] + input[i]);  // dp[index]�Ƿ��뱳����Ʒ�Ĳ�ͬ��Ϸ�ʽ�µĲ�ͬ��ֵ 
		}
	}
	
	return (sum - dp[target]) - dp[target];  // target��sum�н�С����һ�룬��dp[������С��ֵ]<=������С��ֵ�� 
}

int main() {
	int a[] = {2, 7, 4, 1, 8, 1}, n = 6;
	vector<int> input(a, a + n);
	cout << func(input) << endl;
	return 0;
}
