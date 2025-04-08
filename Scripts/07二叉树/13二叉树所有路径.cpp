// ����¼
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

string toString(int x) {
	string res = "";
	while(x) {
		res += x%10 + '0';
		x /= 10;
	}
	
	for (int i=0, j=res.length()-1; i<j; i++, j--) {
		char temp = res[i];
		res[i] = res[j];
		res[j] = temp;
	}
	
	return res;
}

void func(Tree cur, vector<int> &path, vector<string> &res) {
	if (cur == NULL) return;
	
	path.push_back(cur->val);
	
	if (cur->l == NULL && cur->r == NULL) {
		string curPath = "";
		for (int i=0; i<path.size()-1; i++) {
			curPath += toString(path[i]);
			curPath += "->";
		}
		curPath += toString(path[path.size() - 1]);
		
		res.push_back(curPath);
		return;  // ��ֹ����������Ҫ����return 
	}
	
	if (cur->l) {
		func(cur->l, path, res);
		path.pop_back();
	} 
	if (cur->r) {
		func(cur->r, path, res);
		path.pop_back();
	}
}

void func_concise(Tree cur, string path, vector<string> &res) {
	if (cur == NULL) return;
	
	path += toString(cur->val);
	
	if (cur->l == NULL && cur->r == NULL) {
		res.push_back(path);
		return;
	}
	
	if (cur->l) {
		// path += "->";
		func_concise(cur->l, path+"->", res);  // ͨ�������õĴ���ʵ�ֻ��ݡ����ʹ��`path += "->"`�������л�������`->` ����Ϊ�˴�`+=`��`->`��Ҳ��ı�path������`if (cur->r) {}`�е�ֵ �� 
	}
	if (cur->r) {
		func_concise(cur->r, path+"->", res);
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
	
	vector<string> res;
	vector<int> path;
	string path_string = "";
	
	func_concise(root, path_string, res);
	for(int i=0; i<res.size(); i++) {
		printf("%s\n", res[i].c_str());
	}
	
	return 0;
} 
