// reference: https://programmercarl.com/0104.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E6%B7%B1%E5%BA%A6.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
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

int getdepth_digui(Tree cur) {
	if (cur == NULL) return 0;
	
	int ld = getdepth_digui(cur->l);
	int rd = getdepth_digui(cur->r);
	return 1 + (ld>rd?ld:rd);
}

int getdepth_cengci(Tree root) {
	if (root == NULL) return 0;
	
	queue<Tree> que;
	Tree cur = root;
	que.push(root);
	
	int depth = 0;
	while (!que.empty()) {
		int size = que.size();
		depth++;
		for (int i=0; i<size; i++) {
			cur = que.front();
			que.pop();
			if (cur->l) que.push(cur->l);
			if (cur->r) que.push(cur->r);
		}
	}
	
	return depth;
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
	printf("%d\n", getdepth_cengci(root));
}
