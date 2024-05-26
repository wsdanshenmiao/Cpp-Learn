#include <iostream>

template <typename... Args>
void Print(const Args&... args)
{
	(std::cout << ... << args) << "\n";
}

int main()
{
	Print(1, 1, 5, 97, 'a');
}