// reference: https://programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html#%E6%80%9D%E8%B7%AF
#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
	private:
		stack<int> sin;
		stack<int> sout;
		
	public:
		MyQueue() {
	
		}
		
		void push(int x) {
			sin.push(x);
		}
		
		int pop() {
			if (sout.empty()) {
				while (!sin.empty()) {
					sout.push(sin.top());
					sin.pop();
				}
			}
			
			int res = sout.top();
			sout.pop();
			return res;
		}
		
		int peek() {
			// 相似代码不要直接复制，大项目中不方便维护 
//			if (sout.empty()) {
//				while (!sin.empty()) {
//					sout.push(sin.top());
//					sin.pop();
//				}
//			}
			int res = this->pop();
			sout.push(res);
			return res;
		}
		
		bool empty() {
			return sout.empty() && sin.empty();
		}
};

int main() {
	return 0;
}
