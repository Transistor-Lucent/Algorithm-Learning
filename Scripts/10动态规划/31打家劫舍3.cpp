// 随想录
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

vector<int> houxv(Tree cur) {
	if (cur == NULL) return vector<int>(2, 0);
	
	vector<int> left = houxv(cur->l);  // 下标0为取当前节点，下标1为不取当前节点 
	vector<int> right = houxv(cur->r);
	
	int countCur = cur->val + left[1] + right[1]; 
	int noCur = max(left[0], left[1]) + max(right[0], right[1]);
	
	vector<int> res(2);
	res[0] = countCur;
	res[1] = noCur;
	return res;
}

int func(Tree root) {
	vector<int> res = houxv(root);
	return max(res[0], res[1]);
}

int main() {
	return 0;
}
