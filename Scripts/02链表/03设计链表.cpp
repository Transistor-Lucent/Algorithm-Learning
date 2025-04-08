// 参考：https://programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
#include <iostream>

using namespace std;

class TheList {
	public:
		typedef struct Node {
			int val;
			Node *next;
			Node(int x): val(x), next(NULL) {}
			Node(): val(0), next(NULL) {}
		}Node, *List; 
		
		TheList() {
			dmHead = new Node();
			tail = dmHead;
			size = 0;
		}
		
		TheList(int *a, int n) {
			dmHead = new Node();
			tail = dmHead;
			size = 0;
			
			for (int i=0; i<n; i++) {
				addAtTail(a[i]);
			}
		}
		
		int getIndex(int index) {
			if (index < 0 || index >= size)
				return -1;
				
			List cur = dmHead->next;
			for (int i=0; i<index; i++) {
				cur = cur->next;
			}
			return cur->val;
		}
	
		void addAtHead(int val) {
			List cur = new Node(val);
			cur->next = dmHead->next;
			dmHead->next = cur;
			size++;
			
			if (size == 1) {
				tail = cur;
			}
		}
		
		void addAtTail(int val) {
			List cur = new Node(val);
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			size++;
		}
		
		int addAtIndex(int index, int val) {
			if (index > size)
				return -1;
			if (index <0)
				index = 0;
				
			List pre = dmHead;
			for (int i=0; i<index; i++) {  // 获取添加处的前驱，index是多少就前进多少下 ，从虚拟头节点开始 
				pre = pre->next;
			}
			
			// 插入pre后面 
			List cur = new Node(val); 
			cur->next = pre->next;
			pre->next = cur;
			if (index == size)
				tail = cur; 
			size++;
				
			return 1;
		}
		
		int deleteAtIndex(int index) {
			if (index < 0 || index >= size || size == 0)
				return -1;
				
			List pre = dmHead;
			for (int i=0; i<index; i++) {
				pre = pre->next;
			}
			List deleting = pre->next;
			int val = deleting->val;
			pre->next = pre->next->next;
			delete deleting;
			deleting = NULL;  // 防止deleting成为乱指的野指针 
			
			if (index == size-1) {
				tail = pre;
			}
			size--;
			
			return val; 
		}
		
		void display(int flag=1) {
			for (List cur=dmHead->next; cur!=NULL; cur=cur->next) {
				printf("%d ", cur->val);
			}
			if (flag) 
				cout << endl;
		}
		
		void check(int flag=1) {
			cout << "list: ";
			display();
			cout << "size: " << size << endl;
			if (size > 0)
				cout << "tail->val: " << tail->val << endl;	
			
			if (flag)
				cout << endl;
		}
	
		int getSize() {
			return size;
		}

	private:
		int size;
		List dmHead;
		List tail;
}; 

int main() {
	int a[] = {2, 3, 1, 6, 8};
	int n = 5;
	
	TheList aList(a, n);
	aList.check();
	
	aList.addAtIndex(-7, 5);
	aList.check();
	
	int deleted = aList.deleteAtIndex(1);
	aList.check(0);
	cout << deleted << endl;;
	
	return 0;
}
