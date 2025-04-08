// ����¼
#include <iostream>
#include <vector>
#include <queue>
#include "utility.h"

using namespace std;

// �ĸ����� 
int dir[4][2] = {{-1, 0},  // �� 
				 {1, 0},   // �� 
				 {0, -1},  // �� 
				 {0, 1}};  // �� 

void dfs(vector<vector<int> > ocean, int r, int c, vector<vector<bool> > &visited) {
	if (ocean[r][c] == 0 || visited[r][c] == true)
		return;
		
	visited[r][c] = true;
	for (int i=0; i<4; i++) {
		int newi = r + dir[i][0], newj = c + dir[i][1];
		printf("newi: %d, newj: %d\n", newi, newj);
		if (newi < 0 || newi >= ocean.size() || newj < 0 || newj >= ocean[0].size()) continue;  // Խ��
		dfs(ocean, newi, newj, visited);	
	}
}

void bfs(vector<vector<int> > ocean, int r, int c, vector<vector<bool> > &visited) {
	queue<pair<int, int> > que;
	que.push(pair<int, int>(r, c));
	visited[r][c] = true;
	
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();
		
		for (int i=0; i<4; i++) {
			int newi = cur.first + dir[i][0], newj = cur.second + dir[i][1];
			if (newi < 0 || newi >= ocean.size() || newj < 0 || newj >= ocean[0].size()) continue;
			if (ocean[newi][newj] == 1 && visited[newi][newj] == false) {
				que.push(pair<int, int>(newi, newj));
				visited[newi][newj] = true;
			}
		}
	}
}
	

int func(vector<vector<int> > ocean) {  // ����ocean��δ������Ϊ½�ؾ�res++��������dfs����Χ½�ض����� 
	int n = ocean.size(), m = ocean[0].size();
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	int res = 0;
	pnt2d(visited, "visited"); 
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (visited[i][j] == false && ocean[i][j] != 0) {
				printf("i: %d, j: %d\n", i, j);
				res++;
				// dfs(ocean, i, j, visited);
				bfs(ocean, i, j, visited);
				pnt2d(visited, "visited"); 
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
