// ËæÏëÂ¼ 
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > res;
vector<int> path;

void func(int n, int k, int start) {
	if (path.size() == k) {
		res.push_back(path);
		return;
	}
	
	for (int i=start; i<=n-(k-path.size())+1; i++) {
		path.push_back(i);
		func(n, k, i + 1);
		path.pop_back();
	}
}

int main() {
	int n = 4, k = 2;
	func(n, k, 1);
	for (int i=0; i<res.size(); i++) {
		for (int j=0; j<res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
