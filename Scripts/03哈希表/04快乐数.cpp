// ²Î¿¼£ºhttps://programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <hash_set>

using namespace std;

bool judge(int a);
int getSum(int x);

int main() {
	int a = 19;
	
	bool res = judge(a);
	cout << res << endl;
	
	return 0;
} 

int getSum(int x) {
	int sum = 0;
	
	while (x != 0) {
		sum += (x % 10) * (x % 10); 
		x /= 10;
	}
	
	return sum;
}

bool judge(int a) {
	int sum = getSum(a);
	__gnu_cxx::hash_set<int> set;
	while (sum != 1) {
		if (set.find(sum) == set.end()) {
			set.insert(sum);
		}
		else {
			return false;
		}
		
		sum = getSum(sum);
	}
	
	return true;
}
