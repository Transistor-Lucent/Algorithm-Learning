// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int m, int n) {
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	
	for (int i=1; i<=m; i++) dp[i][1] = 1;
	for (int j=1; j<=n; j++) dp[1][j] = 1;
	pnt2d(dp, "dp");
	for (int i=2; i<=m; i++) {
		for (int j=2; j<=n; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	
	return dp[m][n];
}

int main() {
	int m = 1, n = 10;
	cout << func(m, n) << endl;
	return 0;
}
