// reference: https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#_102-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r, *next;
	Node(): val(0), l(NULL), r(NULL), next(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL), next(NULL) {}
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

void order(Tree cur, vector<vector<int> > &res, int depth) {
	if (cur == NULL) return;
	if (res.size() == depth) res.push_back(vector<int>());
	
	res[depth].push_back(cur->val);
	order(cur->l, res, depth+1);
	order(cur->r, res, depth+1);
}

void cengxv_digui(Tree root, vector<vector<int> > &res) {
	int depth = 0;
	order(root, res, depth);
}

int main() {
	Tree root = new Node(3);
	root->l = new Node(5);
	root->l->l = new Node(8);
	root->l->l->l = new Node(10);
	root->l->l->r = new Node(1);
	root->l->r = new Node(18);
	root->r = new Node(12);
	
	vector<vector<int> > res;
	cengxv_digui(root, res);
	for (int i=0; i<res.size(); i++) {
		printf("[");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	
	return 0;
} 
