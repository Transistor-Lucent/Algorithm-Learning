//´úÂëËæÏëÂ¼£ºhttps://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E6%80%9D%E8%B7%AF 
# include <iostream>
# include <vector>

using namespace std;

class Erfen {
	public:
		int zuobiyoubi(int *num, int target, int n) {
			int l = 0, h = n-1;
			
			while (l <= h) {
				int mid = l + (h-l)/2;
				if (num[mid] == target) return mid;
				else if (num[mid] < target) l = mid + 1;
				else h = mid - 1;
			}
			
			return -1;
		}
		
		int zuobiyoukai(int *num, int target, int n) {
			int l = 0, h = n;
			
			while (l < h) {
				int mid = l + (h-l)/2;
				if (num[mid] == target) return mid;
				else if (num[mid] < target) l = mid + 1;
				else h = mid;
			}
			
			return -1;
		}
}; 

int main() {
	int num[] = {-2, 1, 2, 5, 9, 20, 21};
	Erfen erfen;
	int res1 = erfen.zuobiyoubi(num, 21, 7), res2 = erfen.zuobiyoukai(num, 10, 7);
	cout << res1 << endl;
	cout << res2 << endl;
	
	return 0;
}
