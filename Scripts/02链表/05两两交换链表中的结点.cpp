// ²Î¿¼£ºhttps://programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#%E6%80%9D%E8%B7%AF 
#include <iostream>

using namespace std;

typedef struct Node {
	int val;
	Node *next;
	Node(int x): val(x), next(NULL) {}
	Node(): val(0), next(NULL) {}
}Node, *List;

List create(int *a, int n);
void display(List head);
void flip(List head);

int main() {
	int a[] = {2, 3, 1, 6, 8};
	int n = 5;
	
	List head = create(a, 1);
	display(head);
	flip(head);
	display(head);
	
	return 0;
} 

void flip(List head) {
	for (List cur=head; cur->next && cur->next->next; cur=cur->next->next) {
		List pre = cur->next;
		List sub = pre->next;
		
		pre->next = sub->next;
		sub->next = pre;
		cur->next = sub;
	}
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
