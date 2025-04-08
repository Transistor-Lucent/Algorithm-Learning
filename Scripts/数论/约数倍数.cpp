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
	return a * b / maxgongyinshu(a, b);  // �����Լ��Ϊd����a�ɱ�ʾΪm*d��b�ɱ�ʾΪn*d��a*b�ɱ�ʾΪm*n*d*d�������Լ�����ʣ�m��n���ʣ���m*n*dΪ��С������ 
}

int main() {
	cout << zuixiaogongbei(8, 6) << endl;
	return 0;
}

