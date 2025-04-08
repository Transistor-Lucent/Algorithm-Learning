// ����¼
#include <iostream>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

Tree func_digui(Tree cur, int val) {
	// ��Ȼ�Ϊ�����˳��ݹ飬����ȴ�С��������ҵݹ顣ע��func_digui(Tree, int)�з���ֵ������ʱҪô��ֵ��һ��������Ҫôֱ��return 
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
