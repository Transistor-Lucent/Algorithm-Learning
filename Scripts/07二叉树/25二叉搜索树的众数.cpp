// 随想录 
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

// 左中右遍历
int count = 0;
int maxcnt = 0;
Tree pre; 

void travelsal(Tree cur, vector<int> &res) {
	if (cur == NULL) return;
	
	// 左 
	travelsal(cur->l, res);
	
	// 中
	if (pre == NULL) {
		count = 1;
	} else if (pre->val == cur->val) {
		count++;
	} else {
		count = 1;
	}
	pre = cur;
	
	if (count == maxcnt) {
		res.push_back(cur->val);
	} else if (count > maxcnt) {
		res.clear();
		res.push_back(cur->val);
		maxcnt = count;
	}
	
	// 右
	 travelsal(cur->r, res);
	 
	 return;
}

vector<int> func(Tree root) {
	vector<int> res;
	travelsal(root, res);
	
	return res;
}

int main() {
	Tree root = new Node(18);
	root->l = new Node(8);
	root->l->l = new Node(3);
	root->l->l->l = new Node(1);
	root->l->l->r = new Node(3);
	root->l->r = new Node(10);
	root->r = new Node(18);
	
	vector<int> res = func(root);
	for (int i=0; i<res.size(); i++) {
		printf("%d ", res[i]);
	}
	
	return 0;
} 
