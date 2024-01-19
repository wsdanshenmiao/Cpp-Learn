#include <iostream>

int main()
{
	char* butter = new char[8];
	memset(butter, 10, 8);

	delete[] butter;
}