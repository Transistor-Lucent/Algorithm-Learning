// ����¼
#include <iostream>
#include <vector>
#include <stddef.h>
#include "utility.h"

using namespace std;

template <class T>
class bingcha {
private:
	vector<T> father;
	// vector<int> rank;  // ���ĸ߶ȡ���joinʱ��rankѹ������find��������鷳������Ч��Ҳû����find����·��ѹ�����øߡ��ʴ˴���֮ 
	
public:
	bingcha() {this->father = vector<T>();}
	bingcha(int n) {
		this->father = vector<T>(n, -1);  // father[i]Ϊ�����Ľڵ�Ϊ���ڵ㣬�����ֵΪ�����Ľڵ���Ŀ 
//		this->father[2] = 1;
//		this->father[3] = 2;
//		this->father[1] = -3;
		
		// init(n);
		// rank = vector<int>(n, 1);
	}
	vector<T> getFather() {return this->father;}
	
	// �ж� u �� v�Ƿ��ҵ�ͬһ����
	bool isSame(int u, int v) {
    	u = find(u);
    	v = find(v);
    	return u == v;
	}

	// ���鼯��ʼ��
	void init(int n) {
    	for (int i = 0; i < n; ++i) {
        	this->father[i] = i;
    	}
	}

	// Ѱ�� 
	int find(int u) {
	    if (father[u] < 0) return u;
	    else return father[u] = find(father[u]); // ·��ѹ��
	}
	
	// ���벢�鼯
	void join(int u, int v) {
		u = find(u);
		v = find(v);  // һ��Ҫ�Ȱ�u��v��ֵ��Ϊ����ڵ�ĸ� 
		
		if (u == v) return;
		father[v] = u; 
		return;
	}
	
	// �ڵ��ٵ�������ڵ����� 
	void join_nodes(int u, int v) {
		u = find(u);
		v = find(v);
		
		int ranku = father[u] * -1, rankv = father[v] * -1;
		if (ranku < rankv) {
			father[v] -= ranku;
			father[u] = v;
		} else {
			father[u] -= rankv;
			father[v] = u;
		}
		
		return;
	}	  
};

int main() {
	bingcha<int> b(10);
	pnt1d(b.getFather(), "father");
	b.find(1);
	pnt1d(b.getFather(), "father");
//	b.join(1, 2);
//	b.join(3, 4);
//	pnt1d(b.getFather(), "father");
//	b.join(1, 3);
//	pnt1d(b.getFather(), "father");
	return 0;
}
