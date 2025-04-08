// 参考： https://programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html#%E6%80%9D%E8%B7%AF
# include <iostream>

using namespace std;

class Func {
	public:
		void shuangzhizhen(int *num, int n, int *res) {
			int i = 0, j = n-1, resi = n-1;
			
			while(i <= j) { // 归并思想 
				if (num[i]*num[i] < num[j]*num[j]) {
					res[resi--] = num[j] * num[j];
					j--;
				}
				else {
					res[resi--] = num[i] * num[i];
					i++;
				}
			}
		}
		
		void baoli(int *num, int n) {
			for (int i=0; i<n; i++) {
				num[i] = num[i] * num[i];
			}
			quicksort(num, 0, n-1);
		}
		
		void displayArray(int *num, int n) {
			for (int i=0; i<=n-2; i++) {
				cout << num[i] << ' ';
			}
			cout << num[n-1] << endl;
		}
		
		void quicksort(int *a, int l, int h) {
			int t = a[l], i=l, j=h;
			if (l >= h) return;
			
			while (i < j) {
				while (i < j && a[j] >= t) j--;
				a[i] = a[j];
				while (i < j && a[i] <= t) i++;
				a[j] = a[i];
			}
			a[i] = t;
			
			quicksort(a, l, i-1);
			quicksort(a, i+1, h);
		}
};

int main() {
	Func func;
	
	// 双指针归并 
	int num[] = {-4, -1, 0, 3, 10}, n = 5;
	int *res = new int(n);
	
	func.displayArray(num, n);
	func.shuangzhizhen(num, n, res);
	func.displayArray(res, n);
	
	// 暴力平方后排序 
	int num2[] = {-4, -1, 0, 3, 10}, n2 = 5;
	func.displayArray(num2, n2);
	func.baoli(num2, n2);
	func.displayArray(num2, n2);
	
	return 0;
}
