// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n, int m) {
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	
	for (int j=1; j<=n; j++) {
		printf("j: %d\n", j);
		for (int i=1; i<=j && i<=m; i++) {  // i<=j�ǽ�����Ҫ�Ȳ��Ӵ�i<=m�ǲ��Ӳ��ܴ��ڹ涨�Ĳ��� 
			dp[j] += dp[j - i];
			pnt1d(dp, "dp");
		}
	}
	
	return dp[n];
}

int main() {
	int n = 3, m = 2;
	cout << func(n, m) << endl;
	return 0;
}
