// 随想录
#include <iostream>
#include <vector>

using namespace std;

void func(int n, int k, vector<vector<int> > &res, vector<int> path=vector<int>(), int sum=0, int start=1) {
	if (path.size() == k) {
		if (sum == n) {
			res.push_back(path);
		}
		return;
	}
	
	if (sum >= n) return;
	
	for (int i=start; i<=9-(k-path.size())+1; i++) {
		path.push_back(i);
		func(n, k, res, path, sum+i, i+1);  // 不需要像随想录那样定义那么多全局变量 
		path.pop_back();
	}
	
	return;
}

int main() {
	int k = 2, n = 4;
	
	vector<vector<int> > res;
	func(n, k, res);
	
	for (int i=0; i<res.size(); i++) {
		printf("[");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	return 0;
} 
