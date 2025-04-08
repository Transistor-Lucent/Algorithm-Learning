// reference: https://programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char> &s) {
	for (int i=0, j = s.size()-1; i<s.size()/2; i++, j--) {  // 判断条件也可以是i<j，leecode上也可以通过 
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int main() {
	return 0;
}
