// 随想录
#include <iostream>
#include <vector>
#include <hash_set>
#include <string>
#include <algorithm>
#include "utility.h"

using namespace std;

bool func(string s, vector<string> wd) {
	vector<bool> dp(s.size() + 1, false);  // dp[i]表示s中从第1个到第i个（此处i从1开始，而s: string的下标从0开始。substr函数以字符数量截取，所以不统计s和dp的下标起点可以方便计算） 字符能够由wd表示 
	// __gnu_cxx::hash_set<string> set(wd.begin(), wd.end());
	dp[0] = true;
	
	for(int j=1; j<=s.size(); j++) {
		for (int i=0; i<j; i++) {  // 取s中第j个字符为终点，则其在s中相应的下标就是 j-1，即终止条件为 i<j 
			string word = s.substr(i, j - i);  // 此问题中对物品的遍历是固定s的截取终点，移动截取起点 
			if (find(wd.begin(), wd.end(), word) != wd.end() && dp[i]) {
				dp[j] = true;  // 题目问的是能否用wd中的元素拆分s，而没有要求wd中所有元素都使用到 
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
