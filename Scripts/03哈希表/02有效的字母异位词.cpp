// �ο���https://programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>

using namespace std;

bool judge(string s, string t);

int main() {
	char cs[] = "cat", ct[] = "nagaram";
	string s(cs), t(ct);
	
	bool res = judge(s, t);
	if (res) cout << "Ja" << endl;
	else cout << "Nein" << endl;
	
	return 0;
} 

bool judge(string s, string t) {
	int cnt[26] = {0};
	for (int i=0; i<26; i++) {
		cnt[s[i] - 'a']++; 
	}
	for (int i=0; i<26; i++) {  // ����ֽ�һ������ͳ��string t�и���ĸ�������Ƚ���������ֵ���ͻ������һ������Ŀռ� 
		cnt[t[i] - 'a']--;
	}
	
	for (int i=0; i<26; i++) {
		if (cnt[i] != 0)
			return false; 
	} 
	
	return true;
}
