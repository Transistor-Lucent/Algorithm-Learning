// reference: https://programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html#%E6%80%9D%E8%B7%AF
// reference (priority_queue): https://blog.csdn.net/weixin_36888577/article/details/79937886 
#include <iostream>
#include <vector>
#include <hash_map>
#include <queue>

using namespace std;

class Comparison {
public:
	bool operator()(const pair<int, int> &l, const pair<int, int> &h) {  // ע��operator�������������� 
		return l.second > h.second;  // С�ں��򹹽����� 
	}
};

vector<int> topKFrequent(vector<int>& nums, int k) {
	__gnu_cxx::hash_map<int, int> map;
	for (int i=0; i<nums.size(); i++) {
		map[nums[i]]++;
	}
	
	// <�������е���Ԫ�ص�����, �������е�����, �ȽϷ�������>
	priority_queue<pair<int, int>, vector<pair<int, int> >, Comparison> q;  // �ص㣺�����ȶ��У�priority_queue��ʵ��С���󣩶��� 
	for (__gnu_cxx::hash_map<int, int>::iterator it=map.begin(); it!=map.end(); it++) {
		q.push(*it);
		if (q.size() > k) q.pop();
	}
	
	vector<int> ans(k);
	for (int i=k-1; i>=0; i--) {
		ans[i] = q.top().first;
		q.pop();
	} 
	return ans;
}

int main() {
	return 0;
}
