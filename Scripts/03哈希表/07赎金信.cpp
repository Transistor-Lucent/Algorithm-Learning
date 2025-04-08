// ²Î¿¼£ºhttps://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <string>

using namespace std;

bool func(string ransomNote, string magazine) {
	int alph[26] = {0};
	
	if (ransomNote.length() > magazine.length()) return false;
	
	for (int i=0; i<magazine.length(); i++) {
		alph[magazine[i] - 'a']++;
	}
	
	for (int i=0; i<ransomNote.length(); i++) {
		if (--alph[ransomNote[i] - 'a'] < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << func("abcd", "abegd") << endl;
	return 0;
} 
