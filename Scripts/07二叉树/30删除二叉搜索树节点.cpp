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

Tree func_digui(Tree cur, int key) {
	if (cur == NULL) return NULL;
	
	if (cur->val > key) cur->l = func_digui(cur->l, key);
	else if (cur->val < key) cur->r = func_digui(cur->r, key);
	else {  // 找到了应该删除的节点，分情况操作（各情况详情见随想录） 
		if (cur->l == NULL && cur->r == NULL) {
			delete cur;
			return NULL;
		} else if (cur->l && !cur->r) {
			Tree temp = cur->l;
			delete cur;
			return temp;
		} else if (!cur->l && cur->r) {
			Tree temp = cur->r;
			delete cur;
			return temp;
		} else {
			Tree temp = cur->r;
			while (temp->l) {
				temp = temp->l;
			}
			temp->l = cur->l;
			temp = cur->r;
			delete cur;
			return temp;
		}
	}
	
	return cur;
} 

// 从上往下，记录cur的父节点parent，最后插在parent的左或右 
Tree func_diedai(Tree root, int newVal);

int main() {
	Tree root = new Node(12);
	root->l = new Node(8);
	root->l->l = new Node(3);
	root->l->l->l = new Node(1);
	root->l->l->r = new Node(5);
	root->l->r = new Node(10);
	root->r = new Node(18);
	
	int key = 8;
	root = func_digui(root, key);
	
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
