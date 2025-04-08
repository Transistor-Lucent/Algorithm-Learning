// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n) {
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i=3; i<=n; i++) {
		// dp[i-2]��dp[i-1]��dp[i]����һ�ַ�����ע���Ƿֲ��˷���������dp[i-2]*1 + dp[i-1]*1��������(dp[i-2] + 1) + (dp[i-1] + 1)��
		// ��ע��dp[i-2]��dp[i]����һ��������������һ������������dp[i-1]��dp[i]�У����Ե��ƹ�ʽ��dp[i-2]��dp[i]ֻ��һ���߷� 
		dp[i] = dp[i-2] + dp[i-1]; 
	}
	
	return dp[n];
}

int main() {
	int stair = 5;
	cout << func(stair) << endl;
	return 0;
}
