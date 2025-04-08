// ²Î¿¼£ºhttps://programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <hash_map>
#include <vector>

using namespace std;

vector<int> func(vector<int> a, int sum) {
	__gnu_cxx::hash_map<int, int> map(0);
	for (int i=0; i<a.size(); i++) {
		__gnu_cxx::hash_map<int, int>::iterator it = map.find(sum - a[i]);
		
		if (it != map.end()) {
			vector<int> res;
			res.push_back(it->second);
			res.push_back(i);
			return res;
		}
		else {
			map.insert(pair<int, int>(a[i], i));
		}
	}
	
	return vector<int>(0);
}

int main() {
	int aa[] = {2, 7, 4, 5}, n = 4, sum = 9;
	vector<int> a;
	for (int i=0; i<n; i++) {
		a.push_back(aa[i]);
	}
	
	vector<int> res = func(a, sum);
	for (int i=0; i<2; i++) {
		printf("%d ", res[i]);
	} 
	
	return 0;
}
