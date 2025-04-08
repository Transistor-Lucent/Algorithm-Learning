// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> weight, vector<int> value, int bagWeight) {
	int n = weight.size();
	vector<vector<int> > dp(n, vector<int>(bagWeight + 1, 0));
	
	for (int j=weight[0]; j<=bagWeight; j++) {  // ��һ�г�ʼ��
		dp[0][j] = dp[0][j - weight[0]] + value[0];
	}
	pnt2d(dp, "dp");
	
	for (int i=1; i<n; i++) {
		for (int j=1; j<=bagWeight; j++) {
			if (weight[i] <= j) dp[i][j] = max(dp[i-1][j], dp[i][j-weight[i]] + value[i]);  // ��������µ�value��ͬ�е���
			else dp[i][j] = dp[i-1][j];  // �Ų���ȥ�Ͳ���
		}
	}
	pnt2d(dp, "dp");
	
	return dp[n - 1][bagWeight];
}

int func1d(vector<int> weight, vector<int> value, int bagWeight) {
	int n = weight.size();
	vector<int> dp(bagWeight + 1, 0);
	for (int i=0; i<n; i++) {
		for (int j=weight[i]; j<=bagWeight; j++) {
			dp[j] =  max(dp[j], dp[j-weight[i]] + value[i]);
		}
	}
	pnt1d(dp, "dp");
	
	return dp[bagWeight];
}
	

int main() {
	int w[] = {1, 3, 2};
	int v[] = {15, 20, 40};
	int n = 3, bagWeight = 4; 
	vector<int> weight(w, w + n), value(v, v + n);
	cout << func(weight, value, bagWeight) << endl;
	return 0;
}
