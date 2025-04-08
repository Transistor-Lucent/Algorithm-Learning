// ËæÏëÂ¼
#include <iostream>
#include <vector>
#include <queue>
#include "utility.h"

using namespace std;

int dir[4][2] = {{-1, 0},
				{1, 0},
				{0, -1},
				{0, 1}};
				
vector<vector<int> > dfs(vector<vector<int> > gra, int r, int c) {
	if (gra[r][c] == 0 || gra[r][c] == 2) return gra;
	
	gra[r][c] = 2;
	for (int i=0; i<4; i++) {
		int newi = r + dir[i][0], newj = c + dir[i][1];
		if (newi < 0 || newi >= gra.size() || newj < 0 || newj >= gra[0].size()) continue;
		if (gra[newi][newj] == 1) gra = dfs(gra, newi, newj);
	}
	
	return gra;
}
	

vector<vector<int> > func(vector<vector<int> > gra) {
	if (gra.size() == 0) return gra;
	
	int n = gra.size(), m = gra[0].size();
	
	for (int i=0; i<n; i++) {
		if (gra[i][0] == 1) gra = dfs(gra, i, 0);
		if (gra[i][m-1] == 1) gra = dfs(gra, i, m-1);
	}
	
	for (int j=0; j<m; j++) {
		if (gra[0][j] == 1) gra = dfs(gra, 0, j);
		if (gra[n-1][j] == 1) gra = dfs(gra, n-1, j);
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (gra[i][j] == 1) gra[i][j] = 0;
			else if (gra[i][j] == 2) gra[i][j] = 1;
		}
	}
	
	return gra;
}

int main() {
	int n = 4, m = 5;
	vector<vector<int> > ocean(n, vector<int>(m, 0));
	ocean[0][0] = 1; ocean[0][1] = 1;
	ocean[1][0] = 1; ocean[1][1] = 1;
	ocean[2][2] = 1;
	ocean[3][3] = 1; ocean[3][4] = 1;
	pnt2d(ocean, "before");
	
	ocean = func(ocean);
	pnt2d(ocean, "after");
	return 0; 
}
