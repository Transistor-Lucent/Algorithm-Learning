// 参考：https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html#%E6%80%9D%E8%B7%AF
#include <iostream>

using namespace std;

typedef struct Node {
	int val;
	Node *next;
	Node(int a): val(a), next(NULL) {}
	Node(): val(0), next(NULL) {}
}Node, *List;

List create(int *a, int n);
void display(List head);
int across(List heada, List headb);

int main() {
	int a[] = {2, 3, 1, 6, 8};
	int n = 5;
	
	List heada = create(a, n);
	List headb = heada->next->next->next;
	display(heada);
	display(headb);
	
	int val = across(heada, headb);
	cout << val << endl;
	
	return 0;
} 

int across(List heada, List headb) {
	// 求链表长度 
	int lena = 0, lenb = 0;
	for (List cur=heada->next; cur; cur=cur->next) {
		lena++;
	}
	for (List cur=headb->next; cur; cur=cur->next) {
		lenb++;
	}
	
	// 对齐指针
	List curb = headb->next, cura = heada->next;
	if (lena > lenb) {
		for (int i=0; i<lena - lenb; i++)
			cura = cura->next; 
	}
	else {
		for (int i=0; i<lenb - lena; i++)
			curb = curb->next;
	}
	
	// 寻找交点
	while(cura) {
		if (cura == curb)
			return cura->val;
		
		cura = cura->next;
		curb = curb->next; 
	} 
	
	return 0;
}

List create(int *a, int n) {
	List head = new Node();
	for (int i=0; i<n; i++) {
		List temp = new Node(a[i]);
		temp->next = head->next;
		head->next = temp;
	}
	
	return head;
}

void display(List head) {
	for (List p = head->next; p != NULL; p=p->next) {
		printf("%d ", p->val);
	}
	cout << endl;
} 
