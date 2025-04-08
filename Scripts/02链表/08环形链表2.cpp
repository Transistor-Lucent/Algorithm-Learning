// ²Î¿¼£ºhttps://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
#include <iostream>

using namespace std;

typedef struct Node {
	int val;
	Node *next;
	Node(int a): val(a), next(NULL) {}
	Node(): val(0), next(NULL) {}
}Node, *List;

List create(int *a, int n);
void display(List head, int max);
List findCircle(List head);

int main() {
	int a[] = {2, 3, 1, 6, 8};
	int n = 5;
	
	List head = create(a, n);
	display(head, 2 * n);
	List res = findCircle(head);
	if (res) {
		cout << res->val << endl;
	}
	else {
		cout << "NULL" << endl;
	}
	
	return 0;
} 

List findCircle(List head) {
	List fast = head, slow = head;
	
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		
		if (fast == slow) {
			List indexx = head, indexz = fast;
			while (indexx != indexz) {
				indexx = indexx->next;
				indexz = indexz->next;
			}
			return indexx;
		}
	}
	
	return NULL;
}

List create(int *a, int n) {
	List head = new Node();
	List tail;
	for (int i=0; i<n; i++) {
		List temp = new Node(a[i]);
		temp->next = head->next;
		head->next = temp;
		
		if (i == 0) {
			tail = temp;
		}
	}
	
	tail->next = head->next->next->next;
	
	return head->next;
}

void display(List head, int max) {
	int i;
	List p;
	for (p=head, i=0; p != NULL && i<max; p=p->next, i++) {
		printf("%d ", p->val);
	}
	cout << endl;
} 
