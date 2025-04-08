// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

#define MAX_INT 0x7FFFFFFF

int func(vector<int> coins, int amount) {
	int n = coins.size();
	vector<int> dp(amount + 1, MAX_INT);
	
	dp[0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=coins[i]; j<=amount; j++) {
			if (dp[j-coins[i]] != MAX_INT)
				dp[j] = min(dp[j], dp[j-coins[i]] + 1);  // ���ڵ��б���˳��������ң���dp[j-coins[i]]���ʵ��ǵ�ǰ������С������Ӷ����ǵ��˶��ֵ�ǰ���Ӳ�ҵ���� 
		}
		pnt1d(dp, "dp");
	}
	
	if (dp[amount] == MAX_INT) return -1;
	else return dp[amount];
}

int main() {
	int a[] = {1, 2, 5}, n = 3;
	vector<int> input(a, a + n);
	int amount = 5;
	
	cout << func(input, amount) << endl;
	
	return 0;
}
