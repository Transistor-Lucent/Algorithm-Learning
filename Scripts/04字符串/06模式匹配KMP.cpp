// reference: https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 依照王道《数据结构》P121，4.2.3优化的next，但leetcode上有通过不了的输入案例 
void getNext(vector<int> &next, string s) {
	int j = -1;
	next[0] = -1;
	
	for (int i=1; i<s.length(); i++) {
		printf("i: %d, j: %d\n", i, j);
		while (j > -1 && s[i] != s[j+1]) {
			j = next[j];
		}
		printf("i: %d, j: %d\n", i, j);
		if (s[i] == s[j+1]) {
			j++;
		}
		printf("i: %d, j: %d\n", i, j);
		
		// 优化next[]（见王道《数据结构》P121，4.2.3 KMP算法的进一步优化） 
		int tempJ = j;
//		while (tempJ > -1 && s[i] == s[tempJ + 1]) {
//			printf("(in while) i: %d, tempJ: %d\n", i, tempJ);
//			tempJ = next[tempJ];
//		} 
		next[i] = tempJ;
	}
	
	for (int i=0; i<s.length(); i++) {
		int tempJ = next[i];
		while (tempJ > -1 && s[i] == s[tempJ + 1]) {
			printf("(in while) i: %d, tempJ: %d\n", i, tempJ);
			tempJ = next[tempJ];
		} 
		next[i] = tempJ;
	}
}

void getNext2(vector<int> &next, string s) {
	int j = -1;
	next[0] = -1;
	
	for (int i=1; i<s.length(); i++) {
		while (j > -1 && s[i] != s[j+1]) {
			j = next[j];
		}
		if (s[i] == s[j+1]) {
			j++;
		}
		next[i] = j;
	}
}

void display(vector<int> s, string title="") {
	cout << title << endl;
	for (int i=0; i<s.size(); i++) {
		printf("%2d ", s[i]);
	}
	printf("\n");
}

int strStr(string haystack, string needle) {
	vector<int> next(needle.length()), next2(needle.length());
	getNext(next, needle);
	getNext2(next2, needle);
	
	cout << "needle: " << endl;
	for (int i=0; i<needle.length(); i++) {
		printf("%2c ", needle[i]);
	}
	printf("\n");
	display(next, "next: ");
	display(next2, "next2: ");
	
	int j = -1;
	for (int i=0; i<haystack.length(); i++) {
		while (j > -1 && haystack[i] != needle[j + 1]) {
			j = next[j];
		}
		if (needle[j+1] == haystack[i]) {
			j++;
		}
		if (j == needle.length() - 1) {
			return i - needle.size() + 1;
		}
	}
	
	return -1;
}

int main() {
	string haystack = "babbbbbabb";
	string needle = "bbab";
	cout << strStr(haystack, needle) << endl;
	return 0;
}
