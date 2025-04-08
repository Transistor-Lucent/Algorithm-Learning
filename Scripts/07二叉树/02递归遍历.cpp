// reference: https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.html
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

void qianxv(Tree cur, vector<int> &res) {
	if (cur == NULL) return;
	
	res.push_back(cur->val);
	qianxv(cur->l, res);
	qianxv(cur->r, res);
}

void zhongxv(Tree cur, vector<int> &res) {
	if (cur == NULL) return;
	
	zhongxv(cur->l, res);
	res.push_back(cur->val);
	zhongxv(cur->r, res);
}

void houxv(Tree cur, vector<int> &res) {
	if (cur == NULL) return;
	
	houxv(cur->l, res);
	houxv(cur->r, res);
	res.push_back(cur->val);
}

int main() {
	Tree root = new Node(3);
	root->l = new Node(5);
	root->l->l = new Node(8);
	root->l->l->l = new Node(10);
	root->l->l->r = new Node(1);
	root->l->r = new Node(18);
	root->r = new Node(12);
	
	vector<int> a;
	zhongxv(root, a);
	for (int i=0; i<a.size(); i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
