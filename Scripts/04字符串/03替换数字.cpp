// reference: https://programmercarl.com/kamacoder/0054.%E6%9B%BF%E6%8D%A2%E6%95%B0%E5%AD%97.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>

using namespace std;

string func(string s) {
	// 扩充长度 
	int cnt = 0;
	for (int i=0; i<s.length(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			cnt++;
		}
	}
	int oriLength = s.length();
	s.resize(s.length() + cnt * 5);
	
	// 原地改串 
	for (int i=oriLength-1, j=s.length()-1; i>=0; i--) {
		if (s[i] <= '9' && s[i] >= '0') {
			s[j--] = 'r';
			s[j--] = 'e';
			s[j--] = 'b';
			s[j--] = 'm';
			s[j--] = 'u';
			s[j--] = 'n';
		}
		else {
			s[j--] = s[i];
		}
	}
	
	return s; 
}

int main() {
	string input;
	while (cin >> input) {
		string res = func(input);
		cout << res << endl;
	}
	
	return 0;
}
