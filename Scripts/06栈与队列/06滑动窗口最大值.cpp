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
    deque<int> q;  // �����ݼ����У��洢Ԫ���±�

    for (int i = 0; i < nums.size(); i++) {
        // ά����β
        while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();  // ÿ�ζ���back�����������ѱ��Լ�С��pop��ȥ��ʵ��ͷ��βС�ĵ��������������һ�����ø����ʴ�ʱ������С����һ������Զ��С�� 
        q.push_back(i);
//        printf("i: %d, q: ", i);
//        displayDeque(q);
            
        // ά����ͷ
        while (!q.empty() && q.front() + k <= i) q.pop_front();
            
        // ȡ��ͷΪ���ֵ����ӵ����vector�� 
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
