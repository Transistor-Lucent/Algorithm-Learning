// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(int n, int spc, vector<int> weight, vector<int> val) {
	vector<int> dp(spc + 1, 0);  // ����dp����Ĺ�����ֻ�õ�dp[i-1]���ʿ���ѹ��Ϊһά���� 
//	pnt1d(dp, "dp");
//	for (int j=0; j<=spc; j++) if (j >= weight[0]) dp[j] = val[0];  // ������������Ʒ0��Ӧ���������Ƕ��for�б��� 
//	pnt1d(dp, "dp");
	
	for (int i=0; i<n; i++) {
		for (int j=spc; j>=weight[i]; j--) {  // ���ά���鲻ͬ���˴�Ҫ������� 
			dp[j] = max(dp[j], dp[j-weight[i]] + val[i]);
		}
	}
	pnt1d(dp, "dp"); 			
	
	return dp[spc]; 
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
