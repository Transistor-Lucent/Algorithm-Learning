// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include "utility.h"

#define intmax 0x7fffffff

using namespace std;

int func(vector<vector<int> > gra, int n, int m, int dst) {
	if (gra.size() == 0) return 0;
	
	vector<int> minDis(n + 1, intmax);
	vector<bool> visited(n + 1, false);
	vector<int> father(n + 1, 0);
	
	minDis[1] = 0; 
	father[1] = -1;
	for (int i=1; i<=n; i++) {
		int thisMin = intmax, cur = -1;
		for (int j=0; j<=n; j++) {
			if (visited[j] == false && minDis[j] < thisMin) {
				cur = j;
				thisMin = minDis[j];
			}
		}
		
		visited[cur] = true;
		
		for (int j=0; j<=n; j++) {
			if (visited[j] == false && gra[cur][j] != intmax && gra[cur][j] + minDis[cur] < minDis[j]) {
				minDis[j] = minDis[cur] + gra[cur][j];
				father[j] = cur;
			}
		}
	}
	
	if (minDis[dst] == intmax) return -1;
	else return minDis[dst];
}
				
			
int main() {
	int n = 7, m = 9;
	return 0;
}
