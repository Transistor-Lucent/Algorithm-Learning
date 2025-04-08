// 随想录
#include <iostream>
#include <vector>
#include <list> 
#include "utility.h"

using namespace std;

void pnt(vector<vector<int> > res) {
    for (int i=0; i<res.size()-1; i++) {
        for (int j=0; j<res[i].size()-1; j++) {
            printf("%d ", res[i][j]);
        }
        printf("%d\n", res[i][res[i].size() - 1]);
    }

    // last line
    int i = res.size() - 1;  // 卡码中最后一行带\n为正确。即最后一行不需要单独打印 
    for (int j=0; j<res[i].size()-1; j++)
        printf("%d ", res[i][j]);
    printf("%d", res[i][res[i].size() - 1]);
}

void dfs_matrix(vector<vector<int> > gra, vector<vector<int> > &res, int n, int cur=1, vector<int> path=vector<int>()){
	if (cur == n) {
		res.push_back(path);
		return;
	}
	
	for (int i=1; i<=n; i++) {
		if (gra[cur][i] != 0) {
			path.push_back(i);
			dfs_matrix(gra, res, n, i, path);
			path.pop_back();
		}
	}
}

void dfs_table(vector<list<int> > gra, vector<vector<int> > &res, int n, int cur=1, vector<int> path=vector<int>()) {
	if (cur == n) {
		res.push_back(path);
		return;
	}
	
	for (list<int>::iterator node=gra[cur].begin(); node!=gra[cur].end(); node++) {
		path.push_back(*node);
		dfs_table(gra, res, n, *node, path);
		path.pop_back();
	}
}

void input(int m, vector<vector<int> > &gra_matrix, vector<list<int> > &gra_table) {
    while (m--) {
        int tail, head;
        cin >> tail >> head;
        gra_matrix[tail][head]++;
        gra_table[tail].push_back(head);
    }
}

int main() {
	int n = 5, m = 5;
	// ACM式输入
//	cin >> n >> m;
//	vector<vector<int> > gra_matrix(n + 1, vector<int>(n + 1, 0));
//	vector<list<int> > gra_table(n + 1);
//	input(m, gra_matrix, gra_table);
	
	vector<vector<int> > gra_matrix(n + 1, vector<int>(n + 1, 0));
	gra_matrix[1][3] = 1;
	gra_matrix[3][5] = 1;
	gra_matrix[1][2] = 1;
	gra_matrix[2][4] = 1;
	gra_matrix[4][5] = 1;
	pnt2d(gra_matrix, "gra_matrix");
	
	vector<list<int> > gra_table(n + 1);
	gra_table[1].push_back(3); gra_table[1].push_back(2);
	gra_table[2].push_back(4);
	gra_table[3].push_back(5);
	gra_table[4].push_back(5);
	
	vector<vector<int> > res;
	int start = 1;
	vector<int> path(1, start);
	dfs_matrix(gra_matrix, res, n, start, path);
	if (res.size() == 0) res.push_back(vector<int>(1, -1));
	pnt2d(res, "res_matrix");
	
	res = vector<vector<int> >();
	dfs_table(gra_table, res, n, start, path);
	if (res.size() == 0) res.push_back(vector<int>(1, -1));
	pnt2d(res, "res_table");
	// pnt(res);
	
	return 0;
}
