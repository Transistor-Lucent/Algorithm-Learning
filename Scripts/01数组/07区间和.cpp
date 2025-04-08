// 参考： https://programmercarl.com/kamacoder/0058.%E5%8C%BA%E9%97%B4%E5%92%8C.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>

using namespace std;

pair<vector<vector<int> >, int> create();
void display(vector<int>, int);
void func(vector<int> a, vector<int> pre, int n);

int main() {
	// 取得输入数组和前缀和数组 
	pair<vector<vector<int> >, int> p = create();
	vector<int> a = p.first[0];
	vector<int> pre = p.first[1];
	int n = p.second;
	display(a, n);
	cout << endl;
	display(pre, n);
	cout << endl;
	
	func(a, pre, n);
	
	return 0;
} 

pair<vector<vector<int> >, int> create() {
	int n;
	scanf("%d", &n);
	
	int temp;
	vector<int> a(n), pre(n);
	for (int i=0; i<n; i++) {
		scanf("%d", &temp);
		a[i] = temp;
		
		// 构造前缀和数组 
		if (i == 0) 
			pre[i] = temp;
		else
			pre[i] = temp + pre[i-1];
	}
	
	// 将输入数组和前缀和数组打包
	vector<vector<int> > twoV(2, vector<int>(n));
	twoV[0] = a;
	twoV[1] = pre;
	
	return pair<vector<vector<int> >, int>(twoV, n);
}

void func(vector<int> a, vector<int> pre, int n) {
	int l, h, res;
	scanf("%d %d", &l, &h);
	while(l > -1 && h > -1 && l <= h && l < n && h < n) {
		if (l == 0)
			res = pre[h];
		else
			res = pre[h] - pre[l-1];
		printf("%d\n", res);
			
		scanf("%d %d", &l, &h);
	}
	
}

void display(vector<int> a, int n){
	for (int i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
}
