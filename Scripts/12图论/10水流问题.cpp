// 随想录
#include <iostream>
#include <vector> 
#include <queue>
#include "utility.h"

using namespace std;

int dir[4][2] = {{-1, 0},
				{1, 0},
				{0, -1},
				{0, 1}};

// 从边界开始dfs，把比当前地势高的记作visited=true 
void dfs(vector<vector<int> > gra, vector<vector<bool> > &visited, int r, int c) {
	if (visited == true) return;
	
	visited[r][c] = true;
	for (int i=0; i<4; i++) {
		int newi = dir[i][0], newj = dir[i][1];
		if (newi < 0 || newi >= gra.size() || newj < 0 || newj >= gra[0].size()) continue;
		if (gra[newi][newj] >= gra[r][c]) 
			dfs(gra, visited, newi, newj);
	}
}

int main() {
	return 0;
}
