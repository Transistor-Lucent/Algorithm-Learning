// ����¼
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

int countNode(Tree cur) {
	if (cur == NULL) return 0;
	
	int ld = 0, rd = 0;
	Tree l = cur->l, r = cur->r;
	
	// ��������������ȡ���ȫ����������ȱ�һ��������� 
	while (l) {
		l = l->l;
		ld++;
	}
	while (r) {
		r = r->r;
		rd++;
	}
	
	// һ��������ȫ������ʱ��ֻҪ���������߶���ȣ������������������������Ľڵ�������ø߶ȼ���õ�
	 if (rd == ld) {
	 	return (2 << rd) - 1;  // 2 << n���൱��2��n��2����2��n+1�η���rd�������߶ȣ�rd+1��cur�ĸ߶� 
	 } else {
	 	return countNode(cur->l) + countNode(cur->r) + 1;
	 } 
}

int main() {
	Tree root = new Node(9);
	root->l = new Node(10);
	root->r = new Node(12);
	root->l->l = new Node(13);
	root->l->r = new Node(14);
	root->r->l = new Node(11);
	root->r->r = new Node(16);
	root->l->l->l = new Node(15);
	root->l->l->r = new Node(17);
	root->l->r->l = new Node(20);
	
	vector<vector<int> > res;
	cengxv(root, res);
	
	for (int i=0; i<res.size(); i++) {
		printf("[");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	printf("node cnt: %d", countNode(root));
	
	return 0;
} 
