// 随想录
#include <iostream>
#include <vector>
#include <queue>
#include <hash_map>
#include "utility.h"

using namespace std;

vector<int> bfs(__gnu_cxx::hash_map<int, vector<int> > edges, int n, int e) {
	vector<int> indegree(n, 0);
	for (__gnu_cxx::hash_map<int, vector<int> >::iterator it=edges.begin(); it!=edges.end(); it++) {
		vector<int> head = (*it).second;
		for (int i=0; i<head.size(); i++) {
			indegree[head[i]]++;
		}
	}
	
	queue<int> que;
	for (int i=0; i<n; i++) {
		if (indegree[i] == 0) que.push(i);
	}
	
	vector<int> res;
	while(!que.empty()) {
		int cur = que.front();
		que.pop();
		res.push_back(cur);
		
		vector<int> heads = edges[cur];
		for (int i=0; i<heads.size(); i++) {
			indegree[heads[i]]--;
			if (indegree[heads[i]] == 0) que.push(heads[i]);
		}
	}
	
	if (res.size() != n) return vector<int>(1, -1);  // 不能拓扑排序则输出-1 
	return res;
}

int main() {
	int n, e;
    cin >> n >> e;

    __gnu_cxx::hash_map<int, vector<int> > edges;
    int cnt = e;
    while (cnt--) {
        int rear, head;
        cin >> rear >> head;
        edges[rear].push_back(head);
    }

    vector<int> res = bfs(edges, n, e);
    if (res.size() == 1)
        printf("%d", res[0]);
    else {
        for (int i=0; i<n-1; i++) {
            printf("%d ", res[i]);
        }
        printf("%d", res[n-1]);
    }

	return 0;
}
