// 随想录
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

void cengxv(Tree root, vector<vector<int> > res) {
	if (root == NULL) return;
	
	queue<Tree> que;
	Tree cur = root;
	que.push(root);
	
	while (!que.empty()) {
		int size = que.size();
		vector<int> curVec;
		
		while (size--) {
			cur = que.front();
			que.pop();
			curVec.push_back(cur->val);
			
			if (cur->l) que.push(cur->l);
			if (cur->r) que.push(cur->r);
		}
		res.push_back(curVec);
	}
	
	return;
}

Tree func(vector<int> vec, int l, int h) {
	// 区间不变量为左闭右开，终止条件为l >= h，终止操作即return NULL
	// 找最大值下标，以该下标对应的值构造新节点。分割数组，左边的数组递归得到左子树的根，右边的数组递归得到右子树的根，最后返回本层递归构造的节点 
	return new Node();
}

int main() {
	int a[] = {3, 2, 1, 6, 0, 5}, n = 6;
	vector<int> vec(n);
	for (int i=0; i<n; i++) {
		vec[i] = a[i];
	}
	
	Tree root = func(vec, 0, n);
	vector<vector<int> > res;
	
	cengxv(root, res);
	for (int i=0; i<res.size(); i++) {
		printf("[");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	
	return 0;
} 
