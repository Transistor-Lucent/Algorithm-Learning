// 参考：https://programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html#%E6%80%9D%E8%B7%AF
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
void deleteVerseN(List head, int turnOver);

int main() {
	int a[] = {2, 3, 1, 6, 8};
	int n = 5, turnOver = 1;
	
	List head = create(a, 2);
	display(head);
	deleteVerseN(head, turnOver);
	display(head);
	
	return 0;
} 

void deleteVerseN(List head, int turnOver) {
	List slow = head, fast=head;
	for (int i=0; i<turnOver+1; i++) {  // fast先向前移动n+1而不是n次，是因为删除某一个节点，需要指向这一个节点的前一个结点 
		fast = fast->next;
	}
	
	while (fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}
	
	List temp = slow->next;
	slow->next = temp->next;
	delete temp; 
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
