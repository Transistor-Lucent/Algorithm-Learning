// 参考：https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node {
	int val;
	Node *next;
	Node(int a): val(a), next(NULL) {}
	Node(): val(0), next(NULL) {}
}Node, *List;


List create();
void display(List head);
List delete_noDummy(List head, int d);
List delete_withDummy(List head, int d);

int main() {
	// L head = (L)malloc(sizeof(Node));
	List head = create();
	display(head);
	
	int d = 7;
	List deleted_head = delete_noDummy(head, d);
	display(deleted_head);
	cout << endl;
	
	head = create();
	display(head);
	deleted_head = delete_withDummy(head, d);
	display(deleted_head);
	
	return 0;
} 

List delete_noDummy(List head, int d) {
	while (head != NULL && head->val == d) {
		List temp = head;
		head = head->next;
		delete temp;
	}
	if (head == NULL)
		return head;
	
	List cur = head;
	while(cur->next != NULL) {
		if (cur->next->val == d) {
			List temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}
		else {
			cur = cur->next;
		}
	}
	
	return head;
}

List delete_withDummy(List head, int d) {
	List dm = new Node();
	dm->next = head;
	
	List cur = dm;
	while(cur->next != NULL) {  // 不能用`for(int cur=dm; cur!=NULL && cur->next!=NULL; cur=cur->next)`，因为遇到连续两个要删除的数时，删掉前一个后，cur指向后一个，而循环体只检查cur->next，就会删漏后一个 
		if (cur->next->val == d) {
			List temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}
		else {
			cur = cur->next;
		}
	}
	
	return dm->next;
} 

List create()  {
	List head = new Node(6);
	int a[] = {4, 5, 7, 7, 4, 9};
	for (int i=0; i<6; i++) {
		List p = new Node(a[i]);
		p->next = head;
		head = p;
	}
}

void display(List head) {
	for (List p = head; p != NULL; p=p->next) {
		printf("%d ", p->val);
	}
	cout << endl;
}
