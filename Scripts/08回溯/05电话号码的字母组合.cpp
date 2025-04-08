// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string letterMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int singlestoi(char s) {
	return s - '0';
}

void backtracking(string input, vector<string> &res, string cur="", int index=0) {
	if (cur.length() == input.length()) {
		res.push_back(cur);
		return;
	}
	
	string stringOfNum = letterMap[singlestoi(input[index])];
	for (int i=0; i<stringOfNum.length(); i++) {
		cur += stringOfNum[i];
		backtracking(input, res, cur, index+1);
		cur.erase(cur.end() - 1);
	}
	
	return;
}

int main() {
	vector<string> res;
	string input = "235";
	
	backtracking(input, res);
	for (int i=0; i<res.size(); i++) {
		printf("%s ", res[i].c_str());
	}
	
	return 0;
} 
