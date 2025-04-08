// 随想录
#include <iostream>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

Tree func(Tree t1, Tree t2) {
	// t1为NULL则返回t2，t2为NULL则返回t1，都不NULL就相加到一个节点最后返回这个节点。左右子树用递归 
	if (t1 == NULL) return t2;
	if (t2 == NULL) return t1;
	
	Tree t1->val += t2->val;
	
	t1->l = func(t1->l, t2->l);
	t1->r = func(t1->r, t2->r);
	
	return t1;
}

int main() {
	Tree root = new Node(3);
	root->l = new Node(5);
	root->l->l = new Node(8);
	root->l->l->l = new Node(10);
	root->l->l->r = new Node(1);
	root->l->r = new Node(18);
	root->r = new Node(12);
	
	func(root1, root2);
	
	return 0;
} 
