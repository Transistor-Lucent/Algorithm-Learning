// 随想录
#include <iostream>
#include <vector>

using namespace std;

void func(vector<int> candidates, int target, vector<vector<int> > &res, int sum=0, vector<int> path=vector<int>(), int index=0) {
	if (sum == target) {
		res.push_back(path);
		return;
	}
	if (sum > target) return;
	
	for (int i=index; i<candidates.size(); i++) {
		path.push_back(candidates[i]);
		func(candidates, target, res, sum+candidates[i], path, i);  // `sum+candidates[i]`是隐含的回溯，另一种写法是本句前面写`sum += candidates[i]`，本句后面写`sum -= candidates[i]` 
		path.pop_back();
	}
	
	return;
}

int main() {
	int target = 7;
	int a[] = {2, 3, 6, 7}, n = 4;
	vector<int> candidates;
	for (int i=0; i<n; i++) {
		candidates.push_back(a[i]);
	}
	
	vector<vector<int> > res;
	func(candidates, target, res);
	for (int i=0; i<res.size(); i++) 
	{	printf("[");
		for (int j=0; j<res[i].size(); j++)  {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	
	return 0;
} 
