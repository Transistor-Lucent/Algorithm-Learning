// 随想录
#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &a, int l, int h) {
	if (l >= h) return;
	
	int i = l, j = h;
	int temp = a[i];
	
	while (i < j) {
		while (i < j && a[j] >= temp) j--;
		a[i] = a[j];
		while (i < j && a[i] <= temp) i++;
		a[j] = a[i];
	}
	a[i] = temp;
	
	quickSort(a, l, i-1);
	quickSort(a, i+1, h);
	
	return;
}

void func(vector<int> candidates, int target, vector<vector<int> > &res, vector<bool> used, vector<int> path=vector<int>(), int sum=0, int index=0) {
	if (sum == target) {
		res.push_back(path);
		return;
	}
	if (sum > target) {
		return;
	}
	
	for (int i=index; i<candidates.size(); i++) {
		if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) {  // used[i-1] == true代表当前path中已添加candidates[i-1]（纵向），`candidates相等 && ==false`代表当前层尝试过这个数，此时往下的孩子在左兄弟子树中已经出现过。图解见随想录 
			continue;
		}
		
		path.push_back(candidates[i]);
		used[i] = true;
		func(candidates, target, res, used, path, sum+candidates[i], i+1);
		path.pop_back();
		used[i] = false;
	}
	
	return;
}

int main() {
	int a[] = {10, 1, 2, 7, 6, 1, 5}, n = 7;
	vector<int> candidates;
	for (int i=0; i<n; i++) {
		candidates.push_back(a[i]);
	}
	int target = 8;
	
	// 输入数据的预处理 
	vector<vector<int> > res;
	vector<bool> used(candidates.size(), false);
	quickSort(candidates, 0, candidates.size()-1);
	
	func(candidates, target, res, used);
	
	for (int i=0; i<res.size(); i++) {
		printf("[");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	
	return 0;
} 
