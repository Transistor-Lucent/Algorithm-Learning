// reference: https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

void reverse(vector<int> &res) {
	for (int i=0, j=res.size()-1; i<j; i++, j--) {
		int t = res[i];
		res[i] = res[j];
		res[j] = t;
	}
}

void qianxv(Tree root, vector<int> &res) {
	if (root == NULL) return;
	
	stack<Tree> st;
	Tree cur = root;
	st.push(cur);
	while (!st.empty()) {
		cur = st.top();
		st.pop();
		res.push_back(cur->val);
		
		if (cur->r) st.push(cur->r);  // 栈是先进后出，故想要先访问左，应先入栈右 
		if (cur->l) st.push(cur->l);
	}
}

void zhongxv(Tree root, vector<int> &res) {
	Tree cur = root;
	stack<Tree> st;
	while (cur != NULL || !st.empty()) {
		if (cur) {
			st.push(cur);  // 而不是st.push(cur->l) 
			cur = cur->l;
		}
		else {
			cur = st.top();
			st.pop();
			res.push_back(cur->val);
			cur = cur->r;
		}
	}
}
			 
void houxv(Tree root, vector<int> &res) {
	if (root == NULL) return;
	
	stack<Tree> st;
	Tree cur = root;
	st.push(root);
	
	while (!st.empty()) {
		cur = st.top();
		st.pop();
		res.push_back(cur->val);
		
		if (cur->l) st.push(cur->l);
		if (cur->r) st.push(cur->r);
	}
	reverse(res);
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
	houxv(root, a);
	for (int i=0; i<a.size(); i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
