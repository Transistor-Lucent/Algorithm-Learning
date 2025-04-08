// 随想录
#include <iostream>
#include <stack>
#include <vector>
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

// 小了返回右子树，大了返回左子树。递归赋值左右子树根节点 
Tree func_digui(Tree cur, int l, int h);

// 定位根节点一个while，处理左子树一个while，处理右子树一个while 
Tree func_diedai(Tree root, int l, int h);

int main() {
	Tree root = new Node(12);
	root->l = new Node(8);
	root->l->l = new Node(3);
	root->l->l->l = new Node(1);
	root->l->l->r = new Node(5);
	root->l->r = new Node(10);
	root->r = new Node(18);
	
	int l = 4, h = 9;
	root = func_digui(root, l, h);
	
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
