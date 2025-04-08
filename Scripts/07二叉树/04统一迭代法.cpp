// reference: https://programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%BB%9F%E4%B8%80%E8%BF%AD%E4%BB%A3%E6%B3%95.html#%E6%80%9D%E8%B7%AF
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
		
		if (cur != NULL) {
			st.pop();
			
			if (cur->r) st.push(cur->r);  // 栈先进后出，故入栈顺序与访问顺序相反 
			if (cur->l) st.push(cur->l);
			st.push(cur);
			st.push(NULL);
		}
		else {
			st.pop();
			cur = st.top();
			st.pop();
			res.push_back(cur->val);
		}
	}
}

void zhongxv(Tree root, vector<int> &res) {
	if (root == NULL) return;
	
	stack<Tree> st;
	Tree cur = root;
	st.push(cur);
	
	while (!st.empty()) {
		cur = st.top();
		
		if (cur) {
			st.pop();
			
			if (cur->r) st.push(cur->r);
			st.push(cur);
			st.push(NULL);
			if (cur->l) st.push(cur->l);
		}
		else {
			st.pop();
			res.push_back(st.top()->val);
			st.pop();
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
		st.pop();  // 两种情况第一步都是pop，故可在此处就pop 
		
		if (cur) {
			st.push(cur);
			st.push(NULL);  // 重点。别忘了这一步 
			if (cur->r) st.push(cur->r);
			if (cur->l) st.push(cur->l);  
		}
		else {
			res.push_back(st.top()->val);  // 而不是push_back(cur->val) 
			st.pop();
		}
	}
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
