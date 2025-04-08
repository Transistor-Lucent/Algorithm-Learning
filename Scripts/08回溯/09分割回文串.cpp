// 随想录
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isHuiWen(string s) {
	for (int i=0, j=s.length()-1; i<j; i++, j--) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

void func(string s, vector<vector<string> > &res, vector<string> path=vector<string>(), int index=0) {
	if (index >= s.length()) {
		res.push_back(path);
		return;
	}
	
	for (int i=index; i<s.length(); i++) {
		string curString = s.substr(index, i - index + 1);
		if (isHuiWen(curString)) {
			path.push_back(curString);
		} else {
			continue;  // 当前层不是回文，就没必要往下方走了，转而试试当前层的下一个分割点。同时也避免冗余的pop_back() 
		}
		
		func(s, res, path, i+1);
		path.pop_back();
	}
	
	return;
}

int main() {
	string s = "aab";
	
	vector<vector<string> > res;
	func(s, res);
	for (int i=0; i<res.size(); i++) {
		printf("["); 
		for (int j=0; j<res[i].size(); j++) {
			printf("%s ", res[i][j].c_str());
		}
		printf("]\n");
	}
			
	return 0;
}
