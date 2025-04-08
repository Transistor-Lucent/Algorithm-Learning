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

Tree pre = NULL;

bool func_digui(Tree cur);  // 函数外定义一个Tree pre，中序遍历，遍历当前节点时，使用`if (pre !=NULL && pre->val >= cur->val) return false; else pre = cur` 

bool func_diedai(Tree root) {
	stack<Tree> st;
	Tree cur = root;
	
	while (!st.empty() || cur) {
		if (cur) {
			st.push(cur);
			cur = cur->l;
		}
		else {
			cur = st.top();
			st.pop();
			
			if (pre != NULL && cur->val <= pre->val) return false;
			else pre = cur;
			
			cur = cur->r;
		}
	}
	
	return true;
}

int main() {
	Tree root = new Node(12);
	root->l = new Node(8);
	root->l->l = new Node(3);
	root->l->l->l = new Node(1);
	root->l->l->r = new Node(5);
	root->l->r = new Node(10);
	root->r = new Node(18);
	
	cout << func_diedai(root) << endl;
	
	return 0;
} 
