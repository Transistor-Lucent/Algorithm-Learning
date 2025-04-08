// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n) {
	vector<int> dp(n + 1, 0);
	dp[2] = 1;
	
	for (int i=3; i<=n; i++) {
		for (int j=1; j<=i/2; j++) {  // �൱�ڱ����ָ��� 
			dp[i] = max(dp[i], max((i-j) * j, dp[i-j] * j));  // max�Ĳ�������dp[i]���൱���뵱ǰi�������ָʽ�Ƚ� 
		}
	}
	
	return dp[n];
}

int main() {
	int input = 10;
	cout << func(input) << endl;
	return 0;
}
