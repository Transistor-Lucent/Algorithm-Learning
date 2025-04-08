// reference: https://programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>

using namespace std;

string removeSpace(string s) {  // 重点 
	int slow = 0;
	for (int fast=0; fast<s.length(); fast++) {
		if (s[fast] != ' ') {
			if (slow != 0) s[slow++] = ' ';
			while (fast < s.length() && s[fast] != ' ') {
				s[slow++] = s[fast++];
			}
		}
	}
	
	s.resize(slow);
	return s;
}

void reverse(string &s, int low, int high) {
	for (int i=low, j=high; i<j; i++, j--) {
		char temp;
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

string reverseWords(string s) {  //  去括号后，整体reverse，再对各个单词reverse 
	s = removeSpace(s);
	reverse(s, 0, s.length()-1);
	
	for (int slow = 0, fast = 0; fast<s.length(); fast++) {
		if (s[fast] == ' ' || fast == s.length()) {  // 如果此处没有`|| fast == s.length()`，for循环之后就需要加一句reverse(s, slow, fast-1); 
			reverse(s, slow, fast-1);
			slow = fast + 1;
		}
	}
	
	return s;
}

int main() {
	string s = "   the     sky  isn't          blue    ";
	cout << reverseWords(s) << "| end" << endl;
	return 0;
}
