// 随想录
#include <iostream>
#include <vector>
#include <stddef.h>
#include "utility.h"

using namespace std;

template <class T>
class bingcha {
private:
	vector<T> father;
	// vector<int> rank;  // 树的高度。若join时按rank压缩，则find操作会很麻烦，整体效率也没有在find中做路径压缩来得高。故此处弃之 
	
public:
	bingcha() {this->father = vector<T>();}
	bingcha(int n) {
		this->father = vector<T>(n, -1);  // father[i]为负数的节点为根节点，其绝对值为该树的节点数目 
//		this->father[2] = 1;
//		this->father[3] = 2;
//		this->father[1] = -3;
		
		// init(n);
		// rank = vector<int>(n, 1);
	}
	vector<T> getFather() {return this->father;}
	
	// 判断 u 和 v是否找到同一个根
	bool isSame(int u, int v) {
    	u = find(u);
    	v = find(v);
    	return u == v;
	}

	// 并查集初始化
	void init(int n) {
    	for (int i = 0; i < n; ++i) {
        	this->father[i] = i;
    	}
	}

	// 寻根 
	int find(int u) {
	    if (father[u] < 0) return u;
	    else return father[u] = find(father[u]); // 路径压缩
	}
	
	// 加入并查集
	void join(int u, int v) {
		u = find(u);
		v = find(v);  // 一定要先把u、v的值赋为输入节点的根 
		
		if (u == v) return;
		father[v] = u; 
		return;
	}
	
	// 节点少的树并入节点多的树 
	void join_nodes(int u, int v) {
		u = find(u);
		v = find(v);
		
		int ranku = father[u] * -1, rankv = father[v] * -1;
		if (ranku < rankv) {
			father[v] -= ranku;
			father[u] = v;
		} else {
			father[u] -= rankv;
			father[v] = u;
		}
		
		return;
	}	  
};

int main() {
	bingcha<int> b(10);
	pnt1d(b.getFather(), "father");
	b.find(1);
	pnt1d(b.getFather(), "father");
//	b.join(1, 2);
//	b.join(3, 4);
//	pnt1d(b.getFather(), "father");
//	b.join(1, 3);
//	pnt1d(b.getFather(), "father");
	return 0;
}
