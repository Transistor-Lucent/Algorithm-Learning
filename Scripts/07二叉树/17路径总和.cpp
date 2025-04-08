// 随想录
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

bool travelsal(Tree cur, int lastSum) {
	if (cur->l == NULL && cur->r == NULL) {
		if (cur->val == lastSum) return true;
		else return false;
	}
	
	// bool lBool = false, rBool = false;
	
	if (cur->l) {
		// 易错：lBool = travelsal(cur->l, lastSum - (cur->val)); 这样会需要多定义变量和多余的句子，递归次数也会有多余 
		if (travelsal(cur->l, lastSum - (cur->val))) return true;
	}
	if (cur->r) {
		// rBool = travelsal(cur->r, lastSum - (cur->val));
		if (travelsal(cur->r, lastSum - (cur->val))) return true;
	}
	
	// return lBool || rBool;
	return false;
} 

bool func(Tree root, int sum) {
	if (root == NULL) return false;
	return travelsal(root, sum);
}

bool func_diedai(Tree root, int sum) {
	if (root == NULL) return false;
	
	stack<pair<Tree, int> > st;
	st.push(pair<Tree, int>(root, root->val));
	pair<Tree, int> cur;
	
	while (!st.empty()) {
		cur = st.top();
		st.pop();
		if (cur.first->l == NULL && cur.first->r == NULL && sum == cur.second) return true;
		
		if (cur.first->r) {
			st.push(pair<Tree, int>(cur.first->r, cur.second + cur.first->r->val));
		}
		if (cur.first->l) {
			st.push(pair<Tree, int>(cur.first->l, cur.second + cur.first->l->val));
		}
	}
	
	return false;
}

int main() {
	Tree root = new Node(3);
	root->l = new Node(5);
	root->l->l = new Node(8);
	root->l->l->l = new Node(10);
	root->l->l->r = new Node(1);
	root->l->r = new Node(18);
	root->r = new Node(12);
	
	cout << func_diedai(root, 26) << endl;
	cout << func_diedai(root, 17) << endl;
	cout << func_diedai(root, 16) << endl;
	cout << func_diedai(root, 15) << endl;
	
	return 0;
} 
