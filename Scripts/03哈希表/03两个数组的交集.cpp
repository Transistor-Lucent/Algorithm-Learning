// 参考：https://programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>
#include <hash_set>

using namespace std;
using namespace __gnu_cxx;  // hash_set在该namespace下 

vector<int> jiao(vector<int> a, vector<int> b) {
	hash_set<int> res_set;
	hash_set<int> a_set(a.begin(), a.end());
	
	for (vector<int>::iterator it=b.begin(); it!=b.end(); it++) {
		if (a_set.find(*it) != a_set.end())
			res_set.insert(*it);
	}
	
	return vector<int>(res_set.begin(), res_set.end());
}

int main() {
	int aa[] = {9, 4, 9, 8, 4}, n = 5;
	int ab[] = {4, 9, 5}, m = 3;
	vector<int> a(n), b(m);
	for (int i=0; i<n; i++) {
		a[i] = aa[i];
	}
	for (int i=0; i<m; i++) {
		b[i] = ab[i];
	}
	
	vector<int> res = jiao(a, b);
	for(vector<int>::iterator it=res.begin(); it!=res.end(); it++) {
		printf("%d ", *it);
	}
	
	return 0;
} 
