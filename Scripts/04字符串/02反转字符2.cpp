// reference: https://programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>

using namespace std;

void rvs(string &s, int low, int high) {
	for (int i=low, j=high; i<j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

string reverseStr(string s, int k) {
	for (int i=0; i<s.length(); i += 2 * k) {
		if (i + k - 1 < s.length() - 1) {
			rvs(s, i, i+k-1);
		}
		else {
			rvs(s, i, s.length()-1);
		}
	}
	
	return s;
}

int main() {
	return 0;
}
