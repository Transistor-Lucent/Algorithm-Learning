// ����¼
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef struct Node {
	int val;
	Node *l, *r;
	Node(): val(0), l(NULL), r(NULL) {}
	Node(int x): val(x), l(NULL), r(NULL) {}
}Node, *Tree;

void cengxv(Tree root, vector<vector<int> > res) {
	if (root == NULL) return;
	
	queue<Tree> que;
	Tree cur = root;
	que.push(root);
	
	while (!que.empty()) {
		int size = que.size();
		vector<int> curVec;
		
		while (size--) {
			cur = que.front();
			que.pop();
			curVec.push_back(cur->val);
			
			if (cur->l) que.push(cur->l);
			if (cur->r) que.push(cur->r);
		}
		res.push_back(curVec);
	}
	
	return;
}

Tree func(vector<int> vec, int l, int h) {
	// ���䲻����Ϊ����ҿ�����ֹ����Ϊl >= h����ֹ������return NULL
	// �����ֵ�±꣬�Ը��±��Ӧ��ֵ�����½ڵ㡣�ָ����飬��ߵ�����ݹ�õ��������ĸ����ұߵ�����ݹ�õ��������ĸ�����󷵻ر���ݹ鹹��Ľڵ� 
	return new Node();
}

int main() {
	int a[] = {3, 2, 1, 6, 0, 5}, n = 6;
	vector<int> vec(n);
	for (int i=0; i<n; i++) {
		vec[i] = a[i];
	}
	
	Tree root = func(vec, 0, n);
	vector<vector<int> > res;
	
	cengxv(root, res);
	for (int i=0; i<res.size(); i++) {
		printf("[");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("]\n");
	}
	
	return 0;
} 
