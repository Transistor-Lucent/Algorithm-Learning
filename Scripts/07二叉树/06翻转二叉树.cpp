// reference: https://programmercarl.com/0226.%E7%BF%BB%E8%BD%AC%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%BB%E7%BB%93
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

void swapKids(Tree cur) {
	Tree temp = cur->l;
	cur->l = cur->r;
	cur->r = temp;
}

void cengxv(Tree root, vector<vector<int> > &res) {
	if (root == NULL) return;
	
	queue<Tree> que;
	Tree cur = root;
	que.push(cur);
	
	while (!que.empty()) {
		int size = que.size();
		vector<int> vec;
		
		for (int i=0; i<size; i++) {
			cur = que.front();
			que.pop();
			vec.push_back(cur->val);
			
			if (cur->l) que.push(cur->l);
			if (cur->r) que.push(cur->r);
		}
		res.push_back(vec);
	}
}

void invert_qianxvdigui(Tree cur) {
	if (cur == NULL) return;
	
	swapKids(cur);
	invert_qianxvdigui(cur->l);
	invert_qianxvdigui(cur->r);
}

void invert_zhongxvdiedai(Tree root) {
	if (root == NULL) return;
	
	Tree cur = root;
	stack<Tree> st;
	st.push(root);
	
	while (!st.empty()) {
		cur = st.top();
		st.pop();
		
		if (cur != NULL) {
			if (cur->r) st.push(cur->r);
			st.push(cur);
			st.push(NULL);  // 别忘了这一步 
			if (cur->l) st.push(cur->l);
		}
		else {
			swapKids(st.top());  // 而不是swapKids(cur); 
			st.pop();
		}
	}
}

void invert_qianxvdiedai(Tree root) {
	if (root == NULL) return;
	
	stack<Tree> st;
	Tree cur = root;
	st.push(root);
	
	while (!st.empty()) {
		cur = st.top();
		st.pop();
		swapKids(cur);
		
		if (cur->r) st.push(cur->r);
		if (cur->l) st.push(cur->l);
	}
}

void invert_cengcidiedai(Tree root) {
	if (root == NULL) return;
	
	queue<Tree> que;
	que.push(root);
	Tree cur = root;
	
	while (!que.empty()) {
		int size = que.size();
		
		while (size--) {
			cur = que.front();
			que.pop();
			swapKids(cur);
			
			if (cur->l) que.push(cur->l);
			if (cur->r) que.push(cur->r);
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
	
	vector<vector<int> > res1, res2;
	cengxv(root, res1);
	for (int i=0; i<res1.size(); i++) {
		printf("[");
		for (int j=0; j<res1[i].size(); j++) {
			printf("%d ", res1[i][j]);
		}
		printf("]\n");
	}
	printf("\n");
	
	invert_cengcidiedai(root);
	cengxv(root, res2);
	for (int i=0; i<res2.size(); i++) {
		printf("[");
		for (int j=0; j<res2[i].size(); j++) {
			printf("%d ", res2[i][j]);
		}
		printf("]\n");
	}
	return 0;
}
