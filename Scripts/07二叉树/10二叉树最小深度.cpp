// reference: https://programmercarl.com/0111.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6.html#%E6%80%9D%E8%B7%AF
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

int mindepth_digui(Tree cur) {
	if (cur == NULL) return 0;
	
	int subL = mindepth_digui(cur->l), subR = mindepth_digui(cur->r);
	
	if (cur->l == NULL && cur->r != NULL) return subR + 1;
	else if (cur->l != NULL && cur->r == NULL) subL + 1;
	else return (subR<subL?subR:subL) + 1;
}

int mindepth_diedai(Tree root) {
	if (root == NULL) return 0;
	
	queue<Tree> que;
	Tree cur = root;
	que.push(root);
	int depth = 0;
	
	while (!que.empty()) {
		int size = que.size();
		depth++;
		
		while(size--) {
			cur = que.front();
			que.pop();
			if (cur->l == NULL && cur->r == NULL) return depth;
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
	
	vector<vector<int> > res1;
	cengxv(root, res1);
	for (int i=0; i<res1.size(); i++) {
		printf("[");
		for (int j=0; j<res1[i].size(); j++) {
			printf("%d ", res1[i][j]);
		}
		printf("]\n");
	}
	printf("mindep: %d", mindepth_diedai(root));
	return 0;
} 
