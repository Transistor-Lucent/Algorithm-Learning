#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int any2ten(string s, int radix) {
	int ans = 0;
	for (int i=0; i<s.length(); i++) {
		char t = s[i];
		if (t >= '0' && t <= '9')  
			ans = ans * radix + (t - '0');
		else 
			ans = ans * radix + (t - 'a' + 10);  // 对于t - 'a' + 10，比如16进制中的字母A，它表示的数值大小是10，而它减'a'得0 
	}
	
	return ans;
}

string ten2any(int n, int radix) {
	string ans = "";
	while (n > 0) {
		int yv = n % radix;
		
		if (yv <= 9) {
			ans = char(yv + '0') + ans;
		} else {
			ans = char(yv - 10 + 'A') + ans;
		}
		
		n /= radix;
	}
	
	return ans;
}

int ten2bioro(int n, int radix) {
	stack<int> st;
	while (n > 0) {
		st.push(n % radix);
		n /= radix;
	}
	
	int ans = 0;
	while (!st.empty()) {
		ans = ans * 10 + st.top();
		st.pop();
	}
	
	return ans;
}

int main() {
	cout << any2ten("1000", 16) << endl;
	cout << ten2any(4096, 16) << endl;
	cout << ten2bioro(4096, 16) << endl;
	return 0;
}
