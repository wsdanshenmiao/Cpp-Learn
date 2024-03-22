#include <iostream>

//计算参数包大小
template <typename ...Args>	//模板参数包
void ShowSize(Args... args)	//函数形参参数包
{
	std::cout << sizeof...(args) << std::endl;	//sizeof...运算符用来查询参数包中的元素个数
}

//递归展开参数包
//展开函数终止函数
//template <typename T>
//void ShowParameterPack(const T& value)
//{
//	std::cout << value << std::endl;
//}
//
////终止函数也可以是无参的
//void ShowParameterPack()
//{
//	std::cout << std::endl;
//}
//
////参数包展开函数
//template <typename T, typename ...Args>
//void ShowParameterPack(T value, Args... args)
//{
//	std::cout << value << " ";
//	ShowParameterPack(args...);
//}

//参数为零时调用
//void ShowParameterPack()
//{
//	std::cout << std::endl;
//}
//
//template <typename T>
//void PrintArgs(const T& value)
//{
//	std::cout << value << " ";
//}
//
////使用逗号表达式展开参数包
//template <typename ...Args>
//void ShowParameterPack(Args... args)
//{
//	int arr[] = { (PrintArgs(args), 0)... };
//	std::cout << std::endl;
//}

template<class F, class... Args>
void ShowParameterPack(const F& function, Args&&...args)
{
	int arr[] = {function(args)...};
}

////不使用逗号表达式
//template<class T>
//int PrintArg(const T& value)
//{
//	std::cout << value << " ";
//	return 0;
//}
////展开函数
//template<class ...Args>
//void ShowParameterPack(Args... args)
//{
//	int arr[] = { PrintArg(args)... }; //列表初始化
//	std::cout << std::endl;
//}

int main()
{
	ShowSize(1, 'j', 4.0);
	//ShowParameterPack(1, 'j', "CL");
	ShowParameterPack([](auto value) {std::cout << value << " "; return 0; } , 1, 'j', "CL");
}