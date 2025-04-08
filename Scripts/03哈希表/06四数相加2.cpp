// ²Î¿¼£ºhttps://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;

int func(vector<int> A, vector<int> B, vector<int> C, vector<int> D) {
	__gnu_cxx::hash_map<int, int> umap;
	int cnt = 0;
	
	for (int i=0; i<A.size(); i++) {
		for (int j=0; j<B.size(); j++) {
			umap[A[i] + B[j]]++;
		}
	}
	
	for (int i=0; i<C.size(); i++) {
		for (int j=0; j<D.size(); j++) {
			int balance = 0 - C[i] - D[j];
			if (umap.find(balance) != umap.end()) {
				cnt += umap[balance];
			}
		}
	}
	
	return cnt;
}

int main() {
	cout << func(vector<int>(8), vector<int>(8), vector<int>(8), vector<int>(8)) << endl;
	return 0;
} 
