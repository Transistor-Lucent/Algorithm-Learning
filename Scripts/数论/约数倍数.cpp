#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> suoyougongyinshu(int a, int b) {
	int minor = min(a, b);
	vector<int> res;
	for (int i=1; i<=minor; i++) {
		if (a % i == 0 && b % i == 0)
			res.push_back(i);
	}
	
	return res;
}

int maxgongyinshu(int a, int b) {
	int minor = min(a, b);
	for (int i=minor; i>=2; i--) {
		if (a % i == 0 && b % i == 0)
			return i;
	}
	
	return 1;
}

int zuixiaogongbei(int a, int b) {
	return a * b / maxgongyinshu(a, b);  // 记最大公约数为d，则a可表示为m*d，b可表示为n*d，a*b可表示为m*n*d*d。由最大公约数性质，m、n互质，故m*n*d为最小公倍数 
}

int main() {
	cout << zuixiaogongbei(8, 6) << endl;
	return 0;
}

