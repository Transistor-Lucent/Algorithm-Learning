// ����¼
#include <iostream>
#include <vector>
#include "utility.h"

using namespace std;

// �˴������˼·���������� 

#define maxint 0x7fffffff

// ���ѭ������ͣ��������ڵ㵽������̾��룬�����Ͻ�����Ľڵ���ӵ����� 
int prim(vector<vector<int> > gra) {  // graΪ�ڽӾ��� 
	int v = gra.size();
	
	// ʹ��vector�������Ρ������ڵ� 
	vector<int> minDis(v + 1, maxint);  // ������Ŵ�1��ʼ����¼ĳ���㵽������С���룬���������ʱ�����ľ��룬������������С�������ı�Ȩ�� 
	vector<bool> inTree(v + 1, false);  // ��¼һ���ڵ��Ƿ������� 
	
	int sum = 0;  // ��С�������ı�Ȩ�� 
	for (int i=2; i<=v; i++) {
		 sum == minDis[i];
	}
	return sum;
}

int main() {
	return 0;
}
