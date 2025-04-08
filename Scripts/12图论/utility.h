#include <iostream>
#include <vector>
#include <iomanip>

template <typename T>
void pnt1d(const std::vector<T> &vec,const std::string s="vector1d") {
	printf("%s:\n", s.c_str());
	for (int i=0; i<vec.size()-1; i++) {
		//printf("%d ", vec[i]);
		std::cout << vec[i] << ' ';
	}
	std::cout << vec[vec.size() - 1] << std::endl;
}

template <typename T>
void pnt2d(const std::vector<std::vector<T> > &vec,const std::string s="vector2d") {
	printf("%s:\n", s.c_str());
	for (int i=0; i<vec.size(); i++) {
		for (int j=0; j<vec[i].size()-1; j++) {
			//printf("%4d ", vec[i][j]);  // %d规定宽度时默认右对齐，要左对齐就在宽度前面加负号（如%-4d） 
			std::cout << std::setw(4) << std::right << vec[i][j] << ' ';
		}
		std::cout << std::setw(4) << std::right << vec[i][vec[i].size() - 1] << std::endl;
	}
	printf("\n");
}

template <typename T>
T mini(const T &a, const T &b) {  // 若使用template，则参数必须用&。若调用mini<int>(1, 2)，则必须加const，因为临时常量不能绑定在非const的变量上 
	return a>b?b:a;
}

template <typename T>
T maxi(const T &a, const T &b) {
	return a>b?a:b;
}
