// �ο���https://programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF
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
void reverse408(List head);
void reverseTwoPtr(List head);
void reverseDigui(List head);  // �ص� 

int main() {
	int a[] = {2, 3, 1, 6, 8};
	int n = 5;
	
	List head = create(a, n);
	display(head);
	reverse408(head);
	display(head);
	
	cout << endl;
	
	head = create(a, n);
	display(head);
	reverseTwoPtr(head);
	display(head);
	
	cout << endl;
	
	head = create(a, n);
	display(head);
	reverseDigui(head);
	display(head);
	
	return 0;
} 

void reverse408(List head) {  // ͷָ���ÿգ���ԭ����ͷ�巨���������� 
	List cur = head->next;
	head->next = NULL;
	
	while (cur != NULL) {
		List temp = cur;
		cur = cur->next;
		
		temp->next = head->next;
		head->next = temp;
	}
}

void reverseTwoPtr(List head) {
	List pre = NULL, cur = head->next;  // ������`cur = head->next->next, pre = head->next`����Ϊ�����ᵼ������ֻ��һ�������Ԫ��ʱ��Ҫ�����ж� 
	
	while(cur != NULL) {
		List temp = cur->next;
		cur->next = pre;
		
		pre = cur;
		cur = temp;
	}
	
	head->next = pre;
} 

List digui(List pre, List cur) {
	if (cur == NULL)
		return pre;
		
	List temp = cur->next;
	cur->next = pre;
	pre = cur;
	return digui(pre, temp); 
}

void reverseDigui(List head) {
	head->next = digui(NULL, head->next);
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
