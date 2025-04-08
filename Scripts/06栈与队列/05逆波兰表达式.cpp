// reference: https://programmercarl.com/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int stoi(string s) {
	bool negative = false;
    if (s[0] == '-') {
        negative = true;
        s.erase(s.begin());
    }
    
	int res = 0;
	for (int i=s.length()-1; i>=0; i--) {
		int t = 1, pos = s.length() - 1 - i;
		while (pos--) {
			t *= 10;
		}
		
		res += (s[i] - '0') * t;
	}

	if (negative) res *= -1;
	return res;
}

int evalRPN(vector<string>& tokens) {
	stack<int> st;
	for (int i=0; i<tokens.size(); i++) {
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			int n2 = st.top();
			st.pop();
			int n1 = st.top();
			st.pop();
			if (tokens[i] == "+") st.push(n1 + n2);
			else if (tokens[i] == "-") st.push(n1 - n2);
			else if (tokens[i] == "/") st.push(n1 / n2);
			else if (tokens[i] == "*") st.push(n1 * n2);
		}
		else st.push(stoi(tokens[i]));
	}
	return st.top();
}

int main() {
	cout << stoi("-324") << endl;
	return 0;
}
