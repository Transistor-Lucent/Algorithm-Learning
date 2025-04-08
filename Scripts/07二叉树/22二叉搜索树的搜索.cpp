// 随想录
#include <iostream>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

Tree func_digui(Tree cur, int val) {
	// 相等或为空则退出递归，否则比大小向左或向右递归。注意func_digui(Tree, int)有返回值，调用时要么赋值给一个变量，要么直接return 
	return new Node(); 
}

Tree func_diedai(Tree root, int val) {
	while (root) {
		if (root->val == val) return root;
		else if (root->val < val) root = root->r;
		else root = root->l;
	}
	
	return NULL;
}

int main() {
	Tree root = new Node(12);
	root->l = new Node(8);
	root->l->l = new Node(3);
	root->l->l->l = new Node(1);
	root->l->l->r = new Node(5);
	root->l->r = new Node(10);
	root->r = new Node(18);
	
	Tree res = func_diedai(root, 18);
	if (res) cout << res->val << endl; 
	
	return 0;
} 
