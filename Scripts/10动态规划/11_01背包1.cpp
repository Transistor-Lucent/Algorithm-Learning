// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n, int spc, vector<int> weight, vector<int> val) {
	vector<vector<int> > dp(n, vector<int>(spc + 1, 0));
	pnt2d(dp, "dp");
	for (int j=0; j<=spc; j++) if (j >= weight[0]) dp[0][j] = val[0];
	pnt2d(dp, "dp");
	
	for (int i=1; i<n; i++) {
		printf("i: %d\n", i);
		for (int j=0; j<=spc; j++) {
			printf("j: %d ", j);
			// 注意装入前先判断物品重量 
			if (j >= weight[i])  // 能不能放 
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + val[i]);  // 放了好不好 
			else 
				dp[i][j] = dp[i-1][j];
		}
		printf("\ni = %d end\n\n", i);
	}
	pnt2d(dp, "dp");
	
	return dp[n-1][spc];
}

int main() {
//	int w[] = {2, 2, 3, 1, 5, 2};
//	int v[] = {2, 3, 1, 5, 4, 3};
//	int n = 6, spc = 1;

	int w[] = {1, 3, 4};
	int v[] = {15, 20, 30};
	int n = 3, spc = 4;
	
	vector<int> weight(w, w + n), val(v, v + n);
	cout << func(n, spc, weight, val) << endl;
	return 0;
}
