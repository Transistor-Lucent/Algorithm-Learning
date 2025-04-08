// 随想录
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool valid(string s, int l, int h) {
	if (l > h) return false;
	
	string cur = s.substr(l, h - l + 1);
	if (cur.length() > 1 && cur[0] == '0') return false;
	if (cur.length() > 3) return false;
	
	int sum = 0, weishu = 1, cnt = cur.length();
	while (cnt--) {
		char c = cur[cnt];
		if (c < '0' || c > '9') return false;
		
		sum += (c - '0') * weishu;
		if (sum > 255) return false;
		
		weishu *= 10;
	}
	return true;
}

void func(string s, vector<string> &res, int index=0, int dotN=0) {
	if (dotN == 3) {
		if (valid(s, index, s.length() - 1)) {  // 如果用向(string)path中不断+=s.substr()的方法，回溯时path的删除操作不好进行 
			res.push_back(s);
			return;
		}
		else return;
	}
	
	for (int i=index; i<s.length() && i<=index+2; i++) {
		//printf("index: %d, i: %d, s: %s\n", index, i, s.c_str());
		if (valid(s, index, i)) {
			s.insert(s.begin() + i + 1, '.');
			func(s, res, i+2, dotN+1);
			s.erase(s.begin() + i + 1);
		} else {
			break;  // 此处可以break 
		}
	}
}

int main() {
	string s = "010010";
	vector<string> res;
	
	func(s, res);
	
	for (int i=0; i<res.size(); i++) {
		printf("[%s ]\n", res[i].c_str());
	}
	
	return 0;
}
