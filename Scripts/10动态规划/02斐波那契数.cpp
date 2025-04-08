// ����¼
#include <iostream>
#include <vector>
#include "utility.h"  //<> ��ʾ��ϵͳĿ¼�¿�ʼ������Ȼ��������PATH�����������г���Ŀ¼����������ǰĿ¼��"" ��ʾ�ӵ�ǰĿ¼��ʼ������Ȼ����ϵͳĿ¼��PATH�����������г���Ŀ¼��

using namespace std;

// ���淨 
int func(int n) {
	vector<int> dp(2);
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i=2; i<=n; i++) {
		dp.push_back(dp[i-1] + dp[i-2]);
		pnt1d(dp);
	}
	
	return dp[n];
}

// �ռ��Ż�
int func_memOpt(int n) {
	vector<int> dp(2);
	dp[0] = 0;
	dp[1] = 1;
	int sum = 0; 
	
	for (int i=2; i<=n; i++) {
		sum = dp[0] + dp[1];
		dp[0] = dp[1];
		dp[1] = sum;
		pnt1d(dp, "mem opt");
	}
	
	return dp[1];
}

int main() {
	int n = 10;
	cout << func_memOpt(n) << endl;
	return 0;
}
