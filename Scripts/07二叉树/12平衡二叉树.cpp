// ËæÏëÂ¼
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node {
	int value;
	Node *l, *r;
	Node(): value(0), l(NULL), r(NULL) {};
	Node(int x): value(x), l(NULL), r(NULL) {};
}Node, *Tree;

int func_digui(Tree cur) {  // ºóĞòµİ¹é 
	if (cur == NULL) return 0;
	
	int lh = func_digui(cur->l);
	if (lh == -1) return -1;
	int rh = func_digui(cur->r);
	if (rh == -1) return -1;
	
	int balance = lh - rh;
	if (balance < 0) balance *= -1;
	
	if (balance > 1) return -1;
	else return (lh>rh?lh:rh) + 1;
}

int main() {
	return 0;
} 
