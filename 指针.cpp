#include <iostream>
#include <ostream>
#include <random>
using namespace std;

void f(int n){
	int *p = &n;
	printf("%p,%d",p,*p);
	*p = 888;    //将指针转换为一个整形了
}


int main(){
	int i = 6;
	f(i);
}
