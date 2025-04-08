// ����¼
#include <iostream>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

int func(Tree cur) {
	if (cur == NULL) return 0;
	if (cur->r == NULL && cur->l == NULL) return 0;
	
	int lLeaf = func(cur->l);  // ������Ҷ�Ӿ�����val������Ҷ���������������Ҷ�Ӻ� 
	if (cur->l) {
		if (cur->l->l == NULL && cur->r->r == NULL)
			lLeaf = cur->l->val;
	}
	
	int rLeaf = func(cur->r);  // ����������Ҷ�Ӻ�
	
	return lLeaf + rLeaf; 
	
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
