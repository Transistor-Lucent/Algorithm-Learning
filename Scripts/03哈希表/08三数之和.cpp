// ²Î¿¼£ºhttps://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF
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

vector<vector<int> > threeSum(vector<int> nums) {
	quickSort(nums, 0, nums.size()-1);
	vector<vector<int> > res(0);
	vector<int> cur(3);
	
	for (int i=0; i<nums.size()-2; i++) {
		if (nums[i] > 0) return res;
		if (i > 0 && nums[i] == nums[i-1]) continue;
		
		int l = i+1, h = nums.size() - 1;
		while (l < h) {
			if (nums[i] + nums[l] + nums[h] > 0) h--;
			else if (nums[i] + nums[l] + nums[h] < 0) l++;
			else {
				cur[0] = nums[i];
				cur[1] = nums[l];
				cur[2] = nums[h];
				res.push_back(cur);
				
				// È¥ÖØ
				while (l < h && nums[h] == nums[h-1]) h--;
				while (l < h && nums[l] == nums[l+1]) l++;
				h--;
				l++; 
			}
		}
	}
	
	return res;
}

int main() {
	int a[] = {-1, 0, 1, 2, -1, -4}, n = 6;
	vector<int> nums(n);
	for (int i=0; i<nums.size(); i++) {
		nums[i] = a[i];
	} 
	vector<vector<int> > res = threeSum(nums);
	for (int i=0; i<res.size(); i++) {
		for (int j=0; j<3; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
