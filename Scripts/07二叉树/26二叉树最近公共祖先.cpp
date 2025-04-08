// 随想录
#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

// 以后序遍历实现的回溯
Tree func(Tree cur, Tree q, Tree p) {
	if (cur == q || cur == p || cur == NULL) return cur;
	
	Tree l = func(cur->l, q, p);
	Tree r = func(cur->r, q, p);
	
	if (l && r) return cur;
	else if (l && !r) return l;
	else if (!l && r) return r;
	else return NULL;
} 

int main() {
	Tree root = new Node(12);
	root->l = new Node(8);
	root->l->l = new Node(3);
	root->l->l->l = new Node(1);
	root->l->l->r = new Node(5);
	root->l->r = new Node(10);
	root->r = new Node(18);
	
	Tree q = root->l->l->l, p = root->l->l->r;
	Tree res = func(root, q, p);
	if (res) cout << res->val << endl;
	else cout << "no result" << endl;
	
	return 0;
} 
