#include <iostream>
#include <ostream>

using namespace std;
/*
int fib(int n){
	if (n <= 1){
		return n;
	}
	else{
		return fib(n-1)+ fib(n-2);
	}
}

int main() {
	int n;
	std::cout<<"please enter a number:";
	std::cout<<std::endl;
	std::cin>>n;
	std::cout<<fib(n)<<std::endl;
	return 0;
}
*/

//或者可以使用数组存储，这样就不需要递归。

const int N = 100000;
int f[N] = {0};		//初始化数组长度，N必须为const类型
int fib(int n) {
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i < N; i++) {
		f[i] = (f[i - 1] + f[i - 2])%100000;
	}
	return f[n - 1];
}

int main() {
	int n;
	std::cout<<"please enter a number:";
	std::cout<<std::endl;
	std::cin>>n;
	std::cout<<fib(n)<<std::endl;
	return 0;
}
