#include <iostream>
#include <vector>

//thisָ��
class Person
{
public:

	Person(int age)
	{
		//1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
		this->age = age;
	}

	Person& PersonAddPerson(Person p)
	{
		this->age += p.age;
		//���ض�����
		return *this;
	}

	int age;
};

void test01()
{
	Person p1(10);
	std::cout << "p1.age = " << p1.age << std::endl;

	Person p2(10);
	p2.PersonAddPerson(10).PersonAddPerson(10).PersonAddPerson(10);
	std::cout << "p2.age = " << p2.age << std::endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}

//void ForEach(std::vector<int>& values, void(*print)(int))
//{
//	for (int value : values) {
//		print(value);
//	}
//}
//
//int main()
//{
//	std::vector<int> values = { 0,1,2,3,4,5 };
//	auto lambda = [](int value) {std::cout << value << std::endl; };
//	ForEach(values, lambda);
//}

////����ָ��
//void Print(int value)
//{
//	std::cout << value << std::endl;
//}
//
//void ForEach(std::vector<int>& values, void(*print)(int))
//{
//	for (int value : values) {
//		print(value);
//	}
//}
//
//int main()
//{
//	std::vector<int> values = { 0,1,2,3,4,5 };
//	ForEach(values, Print);
//}
////void HelloWorld()
////{
////	std::cout << "Hello world" << std::endl;
////}
////
////int main()
////{
////	auto function = HelloWorld;
////	void(*functionname) = HelloWorld;
////}

//int main()
//{
//	char* butter = new char[8];
//	memset(butter, 10, 8);
//
//	delete[] butter;
//}