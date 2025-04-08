// reference: https://programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
	stack<char> st;
	for (int i=0; i<s.length(); i++) {
		if (s[i] == '[') st.push(']');
		else if (s[i] == '{') st.push('}');
		else if (s[i] == '(') st.push(')');
		else if (st.empty() || s[i] != st.top()) return false;  // �˴���stΪempty��˵��֮ǰû�����������ţ�����ǰ������������ 
		else if (s[i] == st.top()) st.pop();
	}
	
	return st.empty();
}

int main() {
	string s = "()";
	cout << isValid(s) << endl; 
	return 0;
}
