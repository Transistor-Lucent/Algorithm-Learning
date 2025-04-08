#include <iostream>
#include <vector>

using namespace std;

bool sushu(int n) {
	if (n <= 1) return true;
	
	for (int i=2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	
	return true;
}

int main() {
	cout << sushu(247) << endl;
	return 0;
}
