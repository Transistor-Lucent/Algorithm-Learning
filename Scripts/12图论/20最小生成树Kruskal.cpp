// ����¼
#include <iostream>
#include <vector>
#include <algorithm>
#include "utility.h"

using namespace std;

typedef struct Edge {
	int u, v, val;
	Edge(): u(0), v(0), val(0) {}
	Edge(int x, int y, int z): u(x), v(y), val(z) {}
}Edge;
	

class UFSet {
private:
	vector<int> father;
	
public:
	UFSet() { father = vector<int>(); }
	UFSet(int n) {
		father = vector<int>(n, -1);
	}
	
	int find(int u) {
		if (father[u] < 0) return u;
		else return father[u] = find(father[u]);
	}
	
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		
		if (u == v) return;
		father[v] = u;
		return;
	}
	
	bool isSame(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
		
	void init() {
		for (int i=0; i<father.size(); i++) {
			father[i] = -1;
		}
	}
	
	vector<int> getF() { return this->father; }
};

int kruskal(vector<Edge> edges, int n, int e) {
	sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
		return a.val < b.val;
	});  // �Ա߰�val��С�������� 
	
	UFSet set(n + 1);  // ���������ж�����Ŵ�0��ʼ 
	pnt1d(set.getF(), "father");
	int sum = 0;
	for (int i=0; i<e; i++) {
		Edge edge = edges[i];
		int u = set.find(edge.u), v = set.find(edge.v);
		printf("i: %d, u: %d, v: %d, edge.u: %d, edge.v: %d, edge.val: %d\n", i, u, v, edge.u, edge.v, edge.val);
		if (u != v) {
			printf("*u != v*\n");
			sum += edge.val;
			set.join(edge.u, edge.v);  // set.join(u, v)Ҳ�ɣ�����ͨ�� 
			pnt1d(set.getF(), "father");
		}
	}
	
	return sum;
}

int main() {
	int n, e;
    cin >> n >> e;
    vector<Edge> edges;
    
    int u, v, val;
    int cnt = e;
    while (cnt--) {
        cin >> u >> v >> val;
        edges.push_back(Edge(u, v, val));
    }
    
    cout << kruskal(edges, n, e) << endl;
	return 0;
}
