// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> coins, int amount) {
	int n = coins.size();
	vector<vector<unsigned long int> > dp(n, vector<unsigned long int>(amount + 1, 0));  // ��long long intͨ����leetcode�������� 
	for (int i=0; i<n; i++) dp[i][0] = 1;
	for (int j=1; j<=amount; j++) if (j % coins[0] == 0) dp[0][j] = 1;
	pnt2d(dp, "dp");
	
	for (int i=1; i<n; i++) {
		for (int j=1; j<=amount; j++) {
			if (j >= coins[i]) dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];  // dp[i][j-coins[i]]������dp[i-1][j-coins[i]]��ԭ��ͬ��ȫ���� 
			else dp[i][j] = dp[i-1][j];
		}
	}
	pnt2d(dp, "dp");
	
	return dp[n-1][amount];
}

int func1d(vector<int> coins, int amount) {
	int n = coins.size();
	vector<unsigned long int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=coins[i]; j<=amount; j++) {  // ��j��������������Ϊcions[i]��Ӳ��ֻ����һ�� 
			dp[j] += dp[j - coins[i]];  // ����"16Ŀ���.cpp"����άdp���ж�dp[i-1]�ķ��ʣ����Գ��Ի���Ϊһάdp 
		}
	}
	
	return dp[amount];
}

int main() {
	int ca[] = {1, 2, 5}, n = 3;
	int amount = 5;
	vector<int> input(ca, ca + n);
	cout << func1d(input, amount) << endl;
	return 0;
}
