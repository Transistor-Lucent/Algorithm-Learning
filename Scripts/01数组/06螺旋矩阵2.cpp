// 参考： https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void display(int **a, int n);
void displayV(vector<vector<int> > a, int n);
void func(int **a, int n);

int main() {
	int n=7;
	int **a = new int*[n];
	for (int i=0; i<n; i++) {
		a[i] = new int[n]; 
	}
	
	func(a, n);
	display(a, n);
	
	vector<vector<int> > b(n, vector<int>(n, 0)); // 如果`vector<vector<int>>`，`>>`就会报错，加了空格就没事了 
	displayV(b, n);
	
	return 0;
}  

void display(int **a, int n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << setw(4) << right << a[i][j] << ' ';
		}
		cout << endl;
	}
}

void displayV(vector<vector<int> > a, int n) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

void func(int **a, int n) {
	int cnt = 1;
	
	for (int loop=0; loop < n/2; loop++) {
		for (int i=loop; i<n-loop-1; i++) {  // n-1是最外圈转角的下标。n-1-loop即各圈转角的下标 
			a[loop][i] = cnt++;
		}
		for (int i=loop; i<n-loop-1; i++) {
			a[i][n-loop-1] = cnt++;
		}
		for (int i=n-loop-1; i>loop; i--){
			a[n-loop-1][i] = cnt++;
		}
		for (int i=n-loop-1; i>loop; i--) {
			a[i][loop] = cnt++;
		}
	} 
	
	if (n%2 != 0) a[n/2][n/2] = n * n;
}


