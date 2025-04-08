// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Sort(vector<int> &a, int l, int h) {
	if (l >= h) return;
	
	int i = l, j = h, temp = a[l];
	while (i < j) {
		while (i < j && a[j] >= temp) j--;
		a[i] = a[j];
		while (i < j && a[i] <= temp) i++;
		a[j] = a[i];
	}
	a[i] = temp;
	
	Sort(a, l, i-1);
	Sort(a, i+1, h);
}

int func(vector<int> g, vector<int> s) {
	int n = 0, si = s.size() - 1;
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	
	for (int i=g.size()-1; i>=0; i--) {
		if (si < 0) break;
		if (g[i] <= s[si]) {
			n++;
			si--;
		}
	}
	
	return n;
}

int main() {
	int ga[] = {1, 2, 3}, gn = 3;
	int sa[] = {1, 1}, sn = 2;
	vector<int> g(ga, ga + gn), s(sa, sa + sn);
	
	cout << func(g, s) << endl;
	return 0;
}
