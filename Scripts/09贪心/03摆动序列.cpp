// ����¼
#include <iostream>
#include <vector>

using namespace std;

// ̰��
int tanxin(vector<int> a) {
	int prediff = 0, curdiff = 0;
	int res = 1;
	
	for (int i=0; i<a.size()-1; i++) {
		curdiff = a[i] - a[i+1];
		
		if (curdiff * prediff < 0 || (curdiff != 0 && prediff == 0)) {  // ��ʵ������б�µ����� 
			res++;
			prediff = curdiff;
		}
	}
	
	return res;
}

// ���棨δ���գ�
int donggui(); 

int main() {
	int a[] = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8}, n = 10;
	vector<int> input(a, a + n);
	cout << tanxin(input) << endl;
	return 0;
}
