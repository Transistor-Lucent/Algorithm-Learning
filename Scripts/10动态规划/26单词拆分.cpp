// ����¼
#include <iostream>
#include <vector>
#include <hash_set>
#include <string>
#include <algorithm>
#include "utility.h"

using namespace std;

bool func(string s, vector<string> wd) {
	vector<bool> dp(s.size() + 1, false);  // dp[i]��ʾs�дӵ�1������i�����˴�i��1��ʼ����s: string���±��0��ʼ��substr�������ַ�������ȡ�����Բ�ͳ��s��dp���±������Է�����㣩 �ַ��ܹ���wd��ʾ 
	// __gnu_cxx::hash_set<string> set(wd.begin(), wd.end());
	dp[0] = true;
	
	for(int j=1; j<=s.size(); j++) {
		for (int i=0; i<j; i++) {  // ȡs�е�j���ַ�Ϊ�յ㣬������s����Ӧ���±���� j-1������ֹ����Ϊ i<j 
			string word = s.substr(i, j - i);  // �������ж���Ʒ�ı����ǹ̶�s�Ľ�ȡ�յ㣬�ƶ���ȡ��� 
			if (find(wd.begin(), wd.end(), word) != wd.end() && dp[i]) {
				dp[j] = true;  // ��Ŀ�ʵ����ܷ���wd�е�Ԫ�ز��s����û��Ҫ��wd������Ԫ�ض�ʹ�õ� 
				break;
			}
		}
	}
	
	return dp[s.size()];
}

int main() {
	string s[] = {"apple", "and", "apple"};
	int n = 3;
	vector<string> vec(s, s + n);
	string str = "appleandpple";
	cout << func(str, vec) << endl;;
	return 0;
}
