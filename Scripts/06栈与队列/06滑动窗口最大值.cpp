// reference: https://programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html#%E6%80%9D%E8%B7%AF
// reference: https://writings.sh/post/monotonic-queue
#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

void displayDeque(deque<int> q) {
	while(!q.empty()) {
		printf("%d ", q.front());
		q.pop_front();
	}
	printf("\n");
}


class monoque {
private:
	deque<int> q;

public:
	void pop(int value) {
		if (!q.empty() && q.front() == value) {
			q.pop_front();
		}
	}		
	
	void push(int value) {
		while (!q.empty() && q.back() < value) {
			q.pop_back();
		}
		q.push_back(value);
	}
	
	int front() {
		return q.front();
	}
}; 

vector<int> maxSlidingWindow_usingClass(vector<int> &nums, int k) {
	vector<int> ans;
	monoque mono;
	
	for (int i=0; i<k; i++) {
		mono.push(nums[i]);
	}
	ans.push_back(mono.front());
	
	for (int i=k; i<nums.size(); i++) {
		mono.pop(nums[i - k]);
		mono.push(nums[i]);
		ans.push_back(mono.front());
	} 
	
	return ans;
}


vector<int> maxSlidingWindow_noClass(vector<int>& nums, int k) {
	vector<int> ans;
    deque<int> q;  // 单调递减队列，存储元素下标

    for (int i = 0; i < nums.size(); i++) {
        // 维护队尾
        while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();  // 每次都从back进来，并都把比自己小的pop出去，实现头大尾小的单调。后面进来的一定死得更晚，故此时碰到更小的数一定是永远更小的 
        q.push_back(i);
//        printf("i: %d, q: ", i);
//        displayDeque(q);
            
        // 维护队头
        while (!q.empty() && q.front() + k <= i) q.pop_front();
            
        // 取队头为最大值，添加到结果vector中 
        if (i >= k - 1) ans.push_back(nums[q.front()]);
    }

    return ans;
}


int main() {
	int a[] = {1,3,-1,-3,5,3,6,7};
	vector<int> nums;
	for (int i=0; i<8; i++) {
		nums.push_back(a[i]);
	}
	vector<int> ans = maxSlidingWindow_usingClass(nums, 3);
	for (vector<int>::iterator x=ans.begin(); x!=ans.end(); x++) {
		printf("%d ", *x);
	}
	return 0;
}
