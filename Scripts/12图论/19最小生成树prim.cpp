// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

// 此处代码仅思路，不能运行 

#define maxint 0x7fffffff

// 多次循环，不停更新树外节点到树的最短距离，并不断将最近的节点添加到树中 
int prim(vector<vector<int> > gra) {  // gra为邻接矩阵 
	int v = gra.size();
	
	// 使用vector来“修饰”各个节点 
	vector<int> minDis(v + 1, maxint);  // 顶点序号从1开始。记录某顶点到树的最小距离，或加入树中时到树的距离，可用来计算最小生成树的边权和 
	vector<bool> inTree(v + 1, false);  // 记录一个节点是否在书中 
	
	int sum = 0;  // 最小生成树的边权和 
	for (int i=2; i<=v; i++) {
		 sum == minDis[i];
	}
	return sum;
}

int main() {
	return 0;
}
