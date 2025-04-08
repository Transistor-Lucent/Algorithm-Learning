// 随想录
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

void display(string title, vector<int> vec, int l, int h) {
	printf("%s\n", title.c_str());
	for (int i=l; i<h; i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}

Tree travelsal(vector<int> zhongxv, int zhongl, int zhongh, vector<int> houxv, int houl, int houh) {
	int rootVal = houxv[houh - 1];
	Tree root = new Node(rootVal);
	if (houh - houl == 1) return root;  // 注意不能用`houxv.size() == 1`，应为houxv一直没变，变的只有下标 
	
	// 找中序的分割点 
	int rootIndex_zhongxv = zhongl;
	for (;rootIndex_zhongxv<zhongh; rootIndex_zhongxv++) {  // zhongxv的l、h以及houxv的l、h都是左闭右开，故遍历起点是l，终点是h-1 
		if (zhongxv[rootIndex_zhongxv] == rootVal) {
			break;
		}
	}

	// 分割中序 
	int zhong_leftL = zhongl, zhong_leftH = rootIndex_zhongxv;
	int zhong_rightL = rootIndex_zhongxv + 1, zhong_rightH = zhongh;
	
	// 分割后序
	int hou_leftL = houl, hou_leftH = houl + (rootIndex_zhongxv - zhongl);
	int hou_rightL = houl + (rootIndex_zhongxv - zhongl), hou_rightH = houh - 1;  // 后序的最后一个作为根节点拿了出来 
	
	// 递归得到左右子树 
	root->l = travelsal(zhongxv, zhong_leftL, zhong_leftH, houxv, hou_leftL, hou_leftH);
	root->r = travelsal(zhongxv, zhong_rightL, zhong_rightH, houxv, hou_rightL, hou_rightH);
	return root; 
} 

Tree func(vector<int> zhongxv, vector<int> houxv) {
	if (zhongxv.size() == 0 || houxv.size() == 0) return NULL;
	return travelsal(zhongxv, 0, zhongxv.size(), houxv, 0, houxv.size());
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

int main() {
	int zhongxva[] = {10, 8, 1, 5, 18, 3, 12};
	int houxva[] = {10, 1, 8, 18, 5, 12, 3};
	int n = 7;
	vector<int> zhongxv(n), houxv(n);
	for (int i=0; i<n; i++) {
		zhongxv[i] = zhongxva[i];
		houxv[i] = houxva[i];
	}
	
	Tree root = func(zhongxv, houxv);
	
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
