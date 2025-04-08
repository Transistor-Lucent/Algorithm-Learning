// 参考：https://programmercarl.com/kamacoder/0044.%E5%BC%80%E5%8F%91%E5%95%86%E8%B4%AD%E4%B9%B0%E5%9C%9F%E5%9C%B0.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>
#include <cmath>

#define INT_MAX 0x7fffffff

using namespace std;

pair<vector<vector<int> >, vector<int> > create();
void display(vector<vector<int> > a, int n, int m);
int func(vector<vector<int> > a, int n, int m, int sum, vector<int> rowSum);

int main() {
	pair<vector<vector<int> >, vector<int> > p = create();
	int n = p.second[0], m = p.second[1], sum = p.second[2];  // 行、列、元素和 
	vector<int> rowSum = p.first[n];  // 各行和 
	p.first.pop_back(); // 从输入矩阵中删去表示各行和的一行（即最后一行） 
	vector<vector<int> > a = p.first;  // 输入矩阵 
	display(a, n, m);
	
	int res = func(a, n, m, sum, rowSum);
	cout << "res = " << res << endl;
} 

int func(vector<vector<int> > a, int n, int m, int sum, vector<int> rowSum) {  // 用事先求出各行和、各列和、总和来简化计算 
	int res = INT_MAX;
	
	int aNoRowSum = 0;	
	for (int i=0; i<n-1; i++) {
		aNoRowSum += rowSum[i]; 
		res = min(res, abs(sum - aNoRowSum - aNoRowSum));
	}
	
	// 计算各列和 
	vector<int> columnSum(m, 0);
	for (int j=0; j<m; j++) {
		for (int i=0; i<n; i++) {
			columnSum[j] += a[i][j];
		}
	}
	
	int aNoColumnSum = 0;
	for (int i=0; i<m-1; i++) {
		aNoColumnSum += columnSum[i];
		res = min(res, abs(sum - aNoColumnSum - aNoColumnSum));
	}
	
	return res;
}

pair<vector<vector<int> >, vector<int> > create() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> para;
	para.push_back(n);
	para.push_back(m);
	
	vector<vector<int> > a(n, vector<int>(m));
	int temp, sum=0;
	vector<int> rowSum(n, 0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d", &temp);
			a[i][j] = temp;
			
			sum += temp;  // 求所有元素的和 
			rowSum[i] += temp;  // 求各行的和 
		}
	}
	para.push_back(sum);
	a.push_back(rowSum);  // 将各行和数组放在输入矩阵的最后一行 
	
	return pair<vector<vector<int> >, vector<int> >(a, para);
}

void display(vector<vector<int> > a, int n, int m) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
