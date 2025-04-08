// 随想录
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

void cengxv(Tree root, vector<vector<int> > &res) {
	if (root == NULL) return;
	
	queue<Tree> que;
	Tree cur = root;
	que.push(cur);
	
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec;
		
		for (int i=0; i<size; i++) {
			cur = que.front();
			que.pop();
			vec.push_back(cur->val);
			
			if (cur->l) que.push(cur->l);
			if (cur->r) que.push(cur->r);
		}
		res.push_back(vec);
	}
}

int countNode(Tree cur) {
	if (cur == NULL) return 0;
	
	int ld = 0, rd = 0;
	Tree l = cur->l, r = cur->r;
	
	// 求左右子树的深度。完全二叉树求深度比一般二叉树简单 
	while (l) {
		l = l->l;
		ld++;
	}
	while (r) {
		r = r->r;
		rd++;
	}
	
	// 一棵树是完全二叉树时，只要左右子树高度相等，就是满二叉树。满二叉树的节点个数可用高度计算得到
	 if (rd == ld) {
	 	return (2 << rd) - 1;  // 2 << n，相当于2乘n个2，即2的n+1次方。rd是子树高度，rd+1即cur的高度 
	 } else {
	 	return countNode(cur->l) + countNode(cur->r) + 1;
	 } 
}

int main() {
	Tree root = new Node(9);
	root->l = new Node(10);
	root->r = new Node(12);
	root->l->l = new Node(13);
	root->l->r = new Node(14);
	root->r->l = new Node(11);
	root->r->r = new Node(16);
	root->l->l->l = new Node(15);
	root->l->l->r = new Node(17);
	root->l->r->l = new Node(20);
	
	vector<vector<int> > res;
	cengxv(root, res);
	
	for (int i=0; i<res.size(); i++) {
		printf("[");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	printf("node cnt: %d", countNode(root));
	
	return 0;
} 
