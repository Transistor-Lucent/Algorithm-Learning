// 代码随想录： https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF
# include <iostream>

using namespace std;

class Func {
	public:
		int baolijie(int *num, int a, int n) {
			int cnt = 0;
			
			for (int i=0; i<n; i++) {
				if (num[i] == a) {
					int t = num[i];
					
					for (int j = i+1; j<n; j++) {
						num[j-1] = num[j];
					}
					
					num[n-1] = t;
					i--; // 如[1, 4, 4, 3]，检测到第一个4时，i的值为1，移动后对应数值是第二个4，如果不i--，在本次循环结束时会有i++，使i的值变为2，这样就跳过了对第二个4的检测 
					n--;
				}
			}
			
			return n;
		}
		
		int kuaiManPtr(int *num, int a, int n) {
			int cnt = 0;
			int slow = 0;
			
			for (int fast=0; fast<n; fast++) {
				if (num[fast] != a) {
					num[slow] = num[fast];
					slow++;
				}
			} 
			
			return slow;
		}
		
		void displayArray(int *num, int n) {
			for (int i=0; i<=n-2; i++) {
				cout << num[i] << ' ';
			}
			cout << num[n-1] << endl;
		}
};

int main() {
	Func func;
	
	int num[] = {1, 2, 2, 5, 9, 20, 2}, n = 7;
	func.displayArray(num, n);
	n = func.baolijie(num, 2, n);
	func.displayArray(num, n);
	
	int num2[] = {1, 2, 2, 5, 9, 20, 2}, n2 = 7;
	func.displayArray(num2, n2);
	n2 = func.kuaiManPtr(num2, 2, n2);
	func.displayArray(num2, n2);
	
	return 0;
} 
