// reference: https://programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
// reference: https://writings.sh/post/algorithm-repeated-string-pattern
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getNext(vector<int> &next, string s) {
	int j = -1;
	next[0] = j;
	
	for (int i=1; i<s.length(); i++) {
		while (j > -1 && s[i] != s[j + 1]) {
			j = next[j];
		}
		if (s[i] == s[j + 1]) {
			j++;
		}
		next[i] = j;
	}
}

bool strStr(string t, string s) {
	vector<int> next(s.length());
	getNext(next, s);
	
	int j = -1;
	for (int i=0; i<t.length(); i++) {
		while (j > -1 && t[i] != s[j + 1]) {
			j = next[j];
		}
		if (t[i] == s[j + 1]) {
			j++;
		}
		if (j == s.length() - 1) {
			return true;
		}
	}
	
	return false;
}

bool repeatedSubstringPattern_doublingString(string s) {
	string t = s + s;
	t.erase(t.begin());
	t.erase(t.end() - 1);
	return strStr(t, s);
}

bool repeatedSubstringPattern_KMP(string s) {
    if (s.length() <= 1) return false;
    
	string q = s;
	q.erase(q.end() - 1);
	
	// 得到q的最长公共前后缀的长度 
	vector<int> nextQ(q.length());
	getNext(nextQ, q);
	int c = nextQ[q.length() - 1] + 1; 
	// 得到q与其最长公共前（后）缀的长度差 
	int d = q.length() - c;
	
	int sl = s.length();
	if (sl % d == 0 && s[c] == s[s.length() - 1] && d > 0) {  // 注意不要写成`if (sl % d == 0)`，原因见[https://writings.sh/post/algorithm-repeated-string-pattern]，KMP算法充分性说明中的“推演的一个细节处理” 
		return true;
	} 
	return false;
}

int main() {
	string s = "a";
	cout << repeatedSubstringPattern(s) << endl;;
	return 0;
}
