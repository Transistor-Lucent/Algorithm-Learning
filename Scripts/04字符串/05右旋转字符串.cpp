// reference: https://programmercarl.com/kamacoder/0055.%E5%8F%B3%E6%97%8B%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>

using namespace std;

void reverse(string &s, int l, int h) {
	for (int i=l, j=h; i<j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

string rightverse(string s, int k) {
	reverse(s, 0, s.length()-1);
	reverse(s, 0, k-1);
	reverse(s, k, s.length()-1);
	
	return s; 
}

int main() {
	string s;
	int k;
	cin >> s;
	cin >> k;
	cout << rightverse(s, k) << endl; 
	return 0;
}
