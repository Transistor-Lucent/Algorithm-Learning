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

bool compare(Tree l, Tree r) {
	if (l == NULL && r == NULL) return true;
	else if (l->val == r->val) {  // 相等有两种情况，即同为NULL或val相同 
		bool waice = compare(l->l, r->r);
		bool neice = compare(l->r, r->l);
		return waice && neice;
	}
	else return false;
}

bool symmetric(Tree root) {
	if (root == NULL) return true;
	return compare(root->l, root->r);	
}

bool symmetric_duilie(Tree root) {
	if (root == NULL) return true;
	
	queue<Tree> que;
	que.push(root->l);
	que.push(root->r);
	
	while (!que.empty()) {
		Tree cur1 = que.front();
		que.pop();
		Tree cur2 = que.front();
		que.pop();
		if (cur1 == NULL && cur2 == NULL) continue;
		else if (cur1->val == cur2->val) {
			que.push(cur1->l);
			que.push(cur2->r);
			
			que.push(cur1->r);
			que.push(cur2->l);
		}
		else return false;
	}
	
	return true;
}

int main() {
	Tree root = new Node(3);
	root->l = new Node(5);
	root->l->l = new Node(8);
	root->l->l->l = new Node(10);
	root->l->l->r = new Node(1);
	root->l->r = new Node(18);
	root->r = new Node(12);
	
	vector<vector<int> > res1;
	cengxv(root, res1);
	for (int i=0; i<res1.size(); i++) {
		printf("[");
		for (int j=0; j<res1[i].size(); j++) {
			printf("%d ", res1[i][j]);
		}
		printf("]\n");
	}
	printf("\n");
	cout << symmetric_duilie(root) << endl;
	
	Tree root1 = new Node(5);
	root1->l = new Node(8);
	root1->r = new Node(8);
	root1->l->l = new Node(9);
	root1->r->r = new Node(9);
	cout << symmetric_duilie(root1) << endl;
}
