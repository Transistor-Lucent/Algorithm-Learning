// �ο���https://programmercarl.com/kamacoder/0044.%E5%BC%80%E5%8F%91%E5%95%86%E8%B4%AD%E4%B9%B0%E5%9C%9F%E5%9C%B0.html#%E6%80%9D%E8%B7%AF
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
	int n = p.second[0], m = p.second[1], sum = p.second[2];  // �С��С�Ԫ�غ� 
	vector<int> rowSum = p.first[n];  // ���к� 
	p.first.pop_back(); // �����������ɾȥ��ʾ���к͵�һ�У������һ�У� 
	vector<vector<int> > a = p.first;  // ������� 
	display(a, n, m);
	
	int res = func(a, n, m, sum, rowSum);
	cout << "res = " << res << endl;
} 

int func(vector<vector<int> > a, int n, int m, int sum, vector<int> rowSum) {  // ������������к͡����к͡��ܺ����򻯼��� 
	int res = INT_MAX;
	
	int aNoRowSum = 0;	
	for (int i=0; i<n-1; i++) {
		aNoRowSum += rowSum[i]; 
		res = min(res, abs(sum - aNoRowSum - aNoRowSum));
	}
	
	// ������к� 
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
			
			sum += temp;  // ������Ԫ�صĺ� 
			rowSum[i] += temp;  // ����еĺ� 
		}
	}
	para.push_back(sum);
	a.push_back(rowSum);  // �����к�������������������һ�� 
	
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
