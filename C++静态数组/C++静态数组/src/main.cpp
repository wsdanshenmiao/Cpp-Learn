#include <iostream>
#include <array>

template<typename T>
void PrintArray(T& data)
{
	for (int i = 0; i < data.size(); i++) {
		std::cout << data[i] << std::endl;
	}
}

int main()
{
	std::array<int, 10> data;
	data[0] = 1;
	data[1] = 2;
	PrintArray(data);
}