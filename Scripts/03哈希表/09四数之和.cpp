// reference: https://programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &a, int l, int h) {
	if (l >= h) return;
	
	int i = l, j = h, temp = a[l];
	
	while (i < j) {
		while (i < j && a[j] >= temp) j--;
		a[i] = a[j];
		while (i < j && a[i] <= temp) i++;
		a[j] = a[i];
	}
	a[i] = temp;
	
	quickSort(a, l, i-1);
	quickSort(a, i+1, h);
}

// 要点：去重和剪枝
vector<vector<int> > fourSum(vector<int>& nums, int target) {
	vector<vector<int> > res(0);
	vector<int> cur(4);
	quickSort(nums, 0, nums.size()-1);
	
	for (int i=0; i<nums.size()-3; i++) {
		if (nums[i] >= 0 && nums[i] > target) break;
		if (i > 0 && nums[i] == nums[i-1]) continue;
		
		for (int j=i+1; j<nums.size()-2; j++) {
			if (nums[i] + nums[j] >= 0 && nums[i] + nums[j] > target) break;  // 注意不要写成：if (nums[j] >= 0 && nums[j] > target)
			if (j > i+1 && nums[j] == nums[j-1]) continue;
			
			int l = j + 1, h = nums.size() - 1;
			while (l < h) {
				if (nums[i] + nums[j] + nums[l] + nums[h] > target) h--;
				else if (nums[i] + nums[j] + nums[l] + nums[h] < target) l++;
				else {
					cur[0] = nums[i];
					cur[1] = nums[j];
					cur[2] = nums[l];
					cur[3] = nums[h];
					res.push_back(cur);
					
					while (l < h && nums[h] == nums[h-1]) h--;
					while (l < h && nums[l] == nums[l+1]) l++;
					h--;
					l++;
				}
			}
		}
	}
	
	return res;
}

int main() {
	int a[] = {1, 0, -1, 0, -2, 2}, n = 6;
	vector<int> v(n);
	for (int i=0; i<n; i++) {
		v[i] = a[i];
	}
	vector<vector<int> > res = fourSum(v, 0);
	for (int i=0; i<res.size(); i++) {
		for (int j=0; j<4; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
