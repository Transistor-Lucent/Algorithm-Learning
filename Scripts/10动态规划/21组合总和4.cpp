// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> input, int target) {
	int n = input.size();
	vector<unsigned long int> dp(target + 1, 0);
	
	dp[0] = 1;
	for (int j=0; j<=target; j++) {  // �����У���������ڲ���Ʒ������ϣ������Ʒ�ڲ����� 
		for (int i=0; i<n; i++) {
			if (input[i] <= j) {
				dp[j] += dp[j - input[i]];
			}
		}
	}
	
	return dp[target];
}

int main() {
	int a[] = {1, 2, 3}, n = 3;
	int target = 4;
	vector<int> input(a, a + n);
	cout << func(input, target) << endl;
	return 0;
}
