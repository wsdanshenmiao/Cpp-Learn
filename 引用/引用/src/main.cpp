#include <iostream>

#define PRINT(X) (std::cout<<(X)<<std::endl)

void self_Add(int& a)
{
	a++;
}

int main()
{
	int a = 5;
	//int& A = a;
	//A = 2;
	self_Add(a);
	PRINT(a);
}