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

// 右左中遍历。pre初值为0 
Tree func_digui(Tree cur, int &pre);

Tree func_diedai(Tree root) {
	if (root == NULL) return NULL;
	
	stack<Tree> st;
	Tree cur = root;
	int pre = 0;
	
	while (!st.empty() || cur) {
		if (cur) {
			st.push(cur);
			cur = cur->r;
		} else {
			cur = st.top();
			st.pop();
			
			cur->val += pre;
			pre = cur->val;
			
			cur = cur->l;
		}
	}
	
	return root;
}

int main() {
	Tree root = new Node(12);
	root->l = new Node(8);
	root->l->l = new Node(3);
	root->l->l->l = new Node(1);
	root->l->l->r = new Node(5);
	root->l->r = new Node(10);
	root->r = new Node(18);
	
	root = func_diedai(root);
	
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
