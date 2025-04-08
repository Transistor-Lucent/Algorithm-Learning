// ËæÏëÂ¼
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

int func(Tree root) {
	if (root == NULL) return 0;
	
	queue<Tree> que;
	Tree cur = root;
	que.push(cur);
	int res = 0;
	
	while (!que.empty()) {
		int size = que.size();
		
		for (int i=0; i<size; i++) {
			cur = que.front();
			que.pop();
			if (i == 0) res = cur->val;
			
			if (cur->l) que.push(cur->l);
			if (cur->r) que.push(cur->r);
		}
	}
	
	return res;
}

int main() {
	Tree root = new Node(3);
	root->l = new Node(5);
	root->l->l = new Node(8);
	root->l->l->l = new Node(10);
	root->l->l->r = new Node(1);
	root->l->r = new Node(18);
	root->r = new Node(12);
	
	cout << func(root) << endl;
	
	return 0;
} 
