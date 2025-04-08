// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

/// 此处代码皆只是思路，无法正确运行 

void dfs(vector<vector<int> > tu, vector<vector<int> > &res, vector<int> &visited, int nodei, vector<int> path=vector<int>()) {
	if () {
		res.push_back(path);
		return;
	}
	
	visited[i] = true;
	for (int j=0; j<tu.size(); j++) {
		if (tu[i][j] != 0 && visited[j] == false) {
			path.push_back(j);
			dfs(tu, res, visited, j, path);
			path.pop_back();
		}
	}
}

vetor<vector<int> > func(vector<vector<int> > tu) {
	vector<int> path;
	vector<bool> visited(res.size(), false);
	vector<vector<int> > res; 
	
	for (int i=0; i<tu.size(); i++) {
		if (!visited[0]) {
			path.push_back(i);
			dfs(tu, res, visited, i, path);
			path.pop_back();
		}
	}
	
	return res;
}

int main() {
	vector<vector<int> > res = func(tu);
	return 0;
}
