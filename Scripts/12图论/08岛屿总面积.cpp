// 随想录
#include <iostream>
#include <queue>
#include <vector>
#include "utility.h"

using namespace std;

int dir[4][2] = {{-1, 0},
				{1, 0},
				{0, -1},
				{0, 1}};
				
// 遍历边缘，遇到陆地就dfs或bfs将该岛的所有陆地变为0。边缘遍历结束后，遍历gra统计陆地数量 
int func(vector<vector<int> > gra) {
	if (gra.size() == 0) return 0;
	int cnt = 0;
	return cnt; 
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
