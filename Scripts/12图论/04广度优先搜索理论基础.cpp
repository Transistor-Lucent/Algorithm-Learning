// 随想录
#include <iostream>
#include <vector>
#include <queue>
#include "utility.h"

using namespace std;

/// 此处代码皆只是思路，无法正确运行 

vector<int> bfs(vector<vector<int> > gra, int start) {  // 使用队列 
	if (gra.size() == 0) return vector<int>();
	
	vector<int> res;
	queue<int> que;
	que.push(start);
	
	vector<bool> visited(gra.size() + 1, false);
	visited[start] = true;
	res.push(start);
	
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		
		for (int i=1; i<=gra.size(); i++) {
			if (gra[cur][i] != 0 && visited[i] == false) {
				que.push(i);
				res.push_back(i);
			}
		}
	}
				
	return res;
}

int main() 
	int start = 1;
	vector<int> res = bfs(gra, start);
	pnt1d(res, "res");
	return 0;
}
