// ²Î¿¼£ºhttps://programmercarl.com/0209.%E9%95%BF%E5%BA%A6%E6%9C%80%E5%B0%8F%E7%9A%84%E5%AD%90%E6%95%B0%E7%BB%84.html#%E6%80%9D%E8%B7%AF
# include <iostream>

using namespace std;

class Func {
	public:
		void displayArray(int *num, int n) {
			for (int i=0; i<=n-2; i++) {
				cout << num[i] << ' ';
			}
			cout << num[n-1] << endl;
		}
		
		int baoli(int *a, int n, int k) {
			int res = n+1;
			
			for (int i=0; i<n; i++) {
				if (a[i] <= k) {
					int sum = 0;
					
					for (int j=i; j<n; j++) {
						sum += a[j];
						
						if (sum >= k){
							res = res > (j-i+1) ? (j-i+1) : res;
							break;
						}
							
					}
				}
			}
			
			return res == n+1 ? 0 : res;
		}
		
		int slideWindow(int *a, int n, int k) {
			int res = n + 1;
			int sum = 0, i = 0;
			
			
			for (int j=0; j<n; j++) {
				sum += a[j];
				
				while (sum >= k) {
					res = res > (j-i+1) ? (j-i+1) : res;
					sum -= a[i++];
				}
			}
			
			return res == n+1 ? 0 : res;
		} 
	
};

int main() {
	Func func;
	int a[] = {2, 3, 1, 2, 4, 3}, n = 6;
	func.displayArray(a, n);
	int res = func.slideWindow(a, n, 11);
	cout << res << endl;
	
	return 0;
} 
