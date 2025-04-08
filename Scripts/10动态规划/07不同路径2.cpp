// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<vector<int> > obs) {
	int m = obs.size(), n = obs[0].size();
	if (obs[0][0] == 1 && obs[m-1][n-1] == 1) return 0;  // �����ص����ϰ��ֱ���ж��޷�����
	 
	vector<vector<int> > dp(m, vector<int>(n, 0));
	for (int i=0; i<m && obs[i][0]==0; i++) dp[i][0] = 1;  // �ϱ߽����߽��У��м���һ���ϰ������������򶼲��ܵ��� 
	for (int j=0; j<n && obs[0][j]==0; j++) dp[0][j] = 1;
	pnt2d(obs, "obs");
	pnt2d(dp, "dp");
	
	for (int i=1; i<m; i++) {
		for (int j=1; j<n; j++) {
			if (obs[i][j] == 1) continue;
			dp[i][j] = dp[i-1][j] + dp[i][j-1];  // ���ϰ��ĵط�dpֵΪ0 
		}
	}
	
	return dp[m-1][n-1];
}

int main() {
	int m = 3, n = 3;
	vector<vector<int> > vec2d(m, vector<int>(n, 0));
	vec2d[1][1] = 1;
	cout << func(vec2d) << endl;
	return 0;
}
