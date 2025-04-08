// ����¼
#include <iostream>
#include <stack>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

// ���ڶ��������������������ߣ���һ��cur->val�����ڵ�֮�䣬��cur��q��p������������� 
Tree func_digui(Tree cur, Tree q, Tree p) {
	if (cur == NULL) return NULL;
	
	if (q->val > cur->val && p->val > cur->val) return func_digui(cur->r, q, p);
	else if (q->val < cur->val && p->val < cur->val) return func_digui(cur->l, q, p);
	else return cur;
} 

Tree func_diedai(Tree cur, Tree q, Tree p) {
	if (cur == NULL) return NULL;
	
	while (cur) {
		if (cur->val < q->val && cur->val < p->val) cur = cur->r;
		else if (cur->val > q->val && cur->val > p->val) cur = cur->l;
		else return cur;
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
	
	Tree q = root->l->l->l, p = root->l->l->r;
	Tree res = func_diedai(root, q, p);
	if (res) cout << res->val << endl;
	else cout << "no result" << endl;
	
	return 0;
} 
