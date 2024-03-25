#include <iostream>
#include <string>

template <typename... Args>
class Expend
{
public:
    Expend(){}
};

template <>
class Expend<>
{
public:
    Expend(){}
};

template <typename T, typename... Args>
class Expend<T, Args...> : public Expend<Args...>
{
public:
    Expend(T value, Args... args) 
        : Expend<Args...>(args...)  //将扩展参数包传给父类
    {
        std::cout << value << std::endl;
    }
};

int main()
{
    Expend<int, double, std::string, char> e(1, 2.5, "HeavenBurn", 'c');
}


////// 基本模板定义
////template<typename... Args>
////struct Expand;
////
////// 递归展开参数包并打印每个类型
////template<typename First, typename... Args>
////struct Expand<First, Args...>
////{
////    static void print() {
////        std::cout << typeid(First).name() << std::endl;
////        Expand<Args...>::print(); // 递归展开剩余参数包
////    }
////};
////
////// 递归终止条件
////template<typename Last>
////struct Expand<Last>
////{
////    static void print() {
////        std::cout << typeid(Last).name() << std::endl;
////    }
////};
//
//////前向声明
////template <typename... Args>
////class Expend;
////
//////展开参数包的终止条件
////template <typename T>
////class Expend<T> 
////{
////public:
////    Expend(T value) 
////    {
////        std::cout << value << std::endl;
////    }
////};
////
//////展开参数包的终止条件
////template <>
////class Expend<> 
////{
////public:
////    Expend() {}
////};
////
//////参数分离递归展开参数包
////template <typename T, typename... Args>
////class Expend<T, Args...> 
////{
////public:
////    Expend(T value, Args... args) 
////    {
////        std::cout << value << std::endl;
////        Expend<Args...> e(args...); //递归调用
////    }
////};
//
////基本情况，展开参数包的终止条件
//template <typename... Args>
//class Expend 
//{    
//};
//
////展开参数包的特化版本
//template <typename T, typename... Args>
//class Expend<T, Args...> 
//{
//public:
//    Expend(T value, Args... args) 
//    {
//        std::cout << value << std::endl;
//        Expend<Args...> e(args...);
//    }
//};
//
//
//int main() {
//    // 定义一个模板参数包，包含int、double和char数组类型
//    //Expand<int, double, char>::print();
//
//    Expend<int, double, std::string, char> e(1, 2.5, "HeavenBurn", 'c');
//
//    return 0;
//}

////计算参数包大小
//template <typename ...Args>	//模板参数包
//void ShowSize(Args... args)	//函数形参参数包
//{
//	std::cout << sizeof...(args) << std::endl;	//sizeof...运算符用来查询参数包中的元素个数
//}
//
////递归展开参数包
////展开函数终止函数
////template <typename T>
////void ShowParameterPack(const T& value)
////{
////	std::cout << value << std::endl;
////}
////
//////终止函数也可以是无参的
////void ShowParameterPack()
////{
////	std::cout << std::endl;
////}
////
//////参数包展开函数
////template <typename T, typename ...Args>
////void ShowParameterPack(T value, Args... args)
////{
////	std::cout << value << " ";
////	ShowParameterPack(args...);
////}
//
////参数为零时调用
////void ShowParameterPack()
////{
////	std::cout << std::endl;
////}
////
////template <typename T>
////void PrintArgs(const T& value)
////{
////	std::cout << value << " ";
////}
////
//////使用逗号表达式展开参数包
////template <typename ...Args>
////void ShowParameterPack(Args... args)
////{
////	int arr[] = { (PrintArgs(args), 0)... };
////	std::cout << std::endl;
////}
//
//template<class F, class... Args>
//void ShowParameterPack(const F& function, Args&&...args)
//{
//	int arr[] = {function(args)...};
//}
//
//////不使用逗号表达式
////template<class T>
////int PrintArg(const T& value)
////{
////	std::cout << value << " ";
////	return 0;
////}
//////展开函数
////template<class ...Args>
////void ShowParameterPack(Args... args)
////{
////	int arr[] = { PrintArg(args)... }; //列表初始化
////	std::cout << std::endl;
////}
//
//int main()
//{
//	ShowSize(1, 'j', 4.0);
//	//ShowParameterPack(1, 'j', "CL");
//	ShowParameterPack([](auto value) {std::cout << value << " "; return 0; } , 1, 'j', "CL");
//}