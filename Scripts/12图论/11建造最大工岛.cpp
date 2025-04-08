// 随想录
#include <iostream>
#include <vector>
#include <queue>
#include <hash_set>
#include <hash_map>
#include "utility.h"

using namespace std;

int dir[4][2] = {{-1, 0},
				{1, 0},
				{0, -1},
				{0, 1}};

// 统计岛屿面积cnt，并把岛屿中各元素的值赋值为mark 
int dfs(vector<vector<int> > &gra, vector<vector<bool> > &visited, int r, int c, int mark, int cnt=0) {
	if (gra[r][c] == 0 || visited[r][c] == true) {
		return cnt;
	}
	
	cnt++;
	visited[r][c] = true;
	gra[r][c] = mark;
	
	for (int i=0; i<4; i++) {
		int newi = r + dir[i][0], newj = c + dir[i][1];
		// printf("r: %d, c: %d, cnt: %d, newi: %d, newj: %d\n",r, c, cnt, newi, newj);
		if (newi < 0 || newi >= gra.size() || newj < 0 || newj >= gra[0].size()) continue;
		cnt = dfs(gra, visited, newi, newj, mark, cnt);
	}
	
	return cnt;
}
		

int func(vector<vector<int> > ocean) {
	if (ocean.size() == 0) return 0;
	
	int n = ocean.size(), m = ocean[0].size();
	vector<vector<bool> > visited(n, vector<bool>(m, false));
	bool allOne = true;
	
	__gnu_cxx::hash_map<int, int> map;
	int mark = 2;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (ocean[i][j] == 0) allOne = false;  // 第二次遍历中，碰到ocean[i][j]为0才尝试填起来并计算面积，如果没有为0的ocean[i][j]，第二次遍历就不会有任何操作。因此在此处单独计算 
			if (visited[i][j] == false && ocean[i][j] == 1) {
				map[mark] = dfs(ocean, visited, i, j, mark);  // 把该岛屿的数字都标作mark 
				mark++;
			}
		}
	}
	pnt2d(ocean, "marked");
	
	if (allOne) return n * m;
	
	__gnu_cxx::hash_set<int> set;
	int res = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (ocean[i][j] == 0) {
				set.clear(); 
				int cnt = 1;  // ocean[i][j]要填起来，也算一个面积，故初始值为1 
				for (int k=0; k<4; k++) {
					int newi = i + dir[k][0], newj = j + dir[k][1];
					if (newi < 0 || newi >= ocean.size() || newj < 0 || newj >= ocean[0].size()) continue;
					if (set.find(ocean[newi][newj]) == set.end()) {
						cnt += map[ocean[newi][newj]];  // 用mark，即ocean[newi][newj]，来访问该岛屿的面积 
						set.insert(ocean[newi][newj]);  // 将该mark加入set，防止该岛屿与ocean[i][j]多个方向相邻导致的重复计算 
					}
				}
				res = res>cnt?res:cnt;
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
	pnt2d(ocean, "before");
	
	cout << func(ocean) << endl;
	return 0;
}
