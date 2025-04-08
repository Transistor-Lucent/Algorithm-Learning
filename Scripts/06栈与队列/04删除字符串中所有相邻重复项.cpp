// reference: https://programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void reverse(string &s) {
	for (int i=0, j=s.length()-1; i<j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

string removeDuplicates(string s) {
	stack<char> st;
	for (int i=0; i<s.length(); i++) {
		if (st.empty() || s[i] != st.top()) st.push(s[i]);
		else st.pop();
	}
	
	int cnt = 0;
	while(!st.empty()) {
		s[cnt++] = st.top();
		st.pop();
	}
	
	s.resize(cnt);
	reverse(s);
	return s;
}

int main() {
	return 0;
}
