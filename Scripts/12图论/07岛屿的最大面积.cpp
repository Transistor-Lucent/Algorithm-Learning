// ËæÏëÂ¼
#include <iostream>
#include <queue>
#include <vector>
#include "utility.h"

using namespace std;

int dir[4][2] = {{-1, 0},
				{1, 0},
				{0, -1},
				{0, 1}};

int dfs(vector<vector<int> > gra, vector<vector<bool> > &visited, int r, int c, int cnt) {
	if (visited[r][c] == true || gra[r][c] == 0) {
		return cnt;
	}
	
	cnt++;
	visited[r][c] = true;
	for (int i=0; i<4; i++) {
		int newi = r + dir[i][0], newj = c + dir[i][1];
		if (newi < 0 || newi >= gra.size() || newj < 0 || newj >= gra[0].size()) continue;
		cnt = dfs(gra, visited, newi, newj, cnt);
	}
	
	return cnt;
}

int bfs(vector<vector<int> > gra, vector<vector<bool> > &visited, int r, int c) {
	int cnt = 0;
	queue<pair<int, int> > que;
	que.push(pair<int, int>(r, c));
	cnt++;
	visited[r][c] = true;
	
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();
		
		for (int i=0; i<4; i++) {
			int newi = cur.first + dir[i][0], newj = cur.second + dir[i][1];
			if (newi < 0 || newi >= gra.size() || newj < 0 || newj >= gra[0].size()) continue; 
			if (visited[newi][newj] == false && gra[newi][newj] != 0) {
				que.push(pair<int, int>(newi, newj));
				cnt++;
				visited[newi][newj] = true;
			}
		}
	}
	
	return cnt;
}

int func(vector<vector<int> > gra) {
	if (gra.size() == 0) return 0;
	
	int r = gra.size(), c = gra[0].size();
	int count = 0, res = 0;
	vector<vector<bool> > visited(r, vector<bool>(c, false));
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (gra[i][j] != 0 && visited[i][j] == false) {
				//count = dfs(gra, visited, i, j, 0);
				count = bfs(gra, visited, i, j);
				res = res>count?res:count;
			}
		}
	}
	
	return res;
}
			

int main() {
	int n = 4, m = 5;
	vector<vector<int> > ocean(n, vector<int>(m, 0));
	ocean[0][0] = 1; ocean[0][1] = 1;
	ocean[1][0] = 1; ocean[1][1] = 1;
	ocean[2][2] = 1;
	ocean[3][3] = 1; ocean[3][4] = 1;
	
	cout << func(ocean) << endl;
	return 0;
}
