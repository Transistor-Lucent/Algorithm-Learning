// reference: https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html#%E6%80%9D%E8%B7%AF
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
	private:
		queue<int> list;
	public:
		MyStack() {}
		
		void push(int x) {
			list.push(x);
		}
		
		int pop() {
			int num = list.size() - 1;
			while (num--)   {// `while(n--)`即循环n次 
//				int temp = list.front();
//				list.pop();
//				list.push(temp);
				
				// 这样写比上面更好 
				list.push(list.front());
				list.pop();
			}
			
			int res = list.front();
			list.pop();
			return res;
		}
		
		int top() {
			int res = this->pop();
			list.push(res);
			return res;
		}
		
		bool empty() {
			return list.empty();
		}
};

int main() {
	return 0;
}
