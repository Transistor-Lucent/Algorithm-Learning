// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

int func(vector<int> input, int target) {
	int sum = 0, n = input.size();
	for (int i=0; i<n; i++) {
		sum += input[i];
	}
	if (abs(target) > sum) return 0;  // ע��������� 
	if ((sum + target) % 2 == 1) return 0;  // �ӷ���Ϊxʱ����x-(sum-x)==target�������x=(target+sum)/2 
	int pos_sum = (sum + target) / 2;
	
	vector<int> dp(pos_sum+1, 0);  
	// ��ʼʱ������Ϊ0��ֻ������Ʒ[0]ʱ��ֻ�в������κ���Ʒһ�ַŷ�����input[0]Ϊ0���������i=0��j=0ʱ��dp[0]��ֵ��`dp[j] += dp[j - input[i]];`��Ϊ2���������˷���input[0]��һ�ַŷ�
	dp[0] = 1;  // ��ʹ�ö�άdp�����ʼ��ʱ����һ�е�ֵ������Ϊ0��Ʒ�����������������һ�е�dp[0][>=1]�У�������ͬinput[0]�����ĵط�Ϊ1�����з���input[0]��һ�ַŷ� 
	for (int i=0; i<n; i++) {
		for (int j=pos_sum; j>=input[i]; j--) {  // ����֤ÿ����ֻ��һ�� 
			dp[j] += dp[j - input[i]];  // dp[j]�ǵ�ǰ�����²���input[i]�ķŷ���dp[j-input[i]]�Ǽ�ȥinput[i]������ķŷ�����ȥ��input[i]�ⲿ��ֻ�з�һ��input[i]��һ�ַ���
		}
	}
			
	return dp[pos_sum];
}

int main() {
	int a[] = {100}, n = 1, target = -200;
	vector<int> input(a, a + n);
	cout << func(input, target) << endl;
	return 0;
}
