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
        : Expend<Args...>(args...)  //����չ��������������
    {
        std::cout << value << std::endl;
    }
};

int main()
{
    Expend<int, double, std::string, char> e(1, 2.5, "HeavenBurn", 'c');
}


////// ����ģ�嶨��
////template<typename... Args>
////struct Expand;
////
////// �ݹ�չ������������ӡÿ������
////template<typename First, typename... Args>
////struct Expand<First, Args...>
////{
////    static void print() {
////        std::cout << typeid(First).name() << std::endl;
////        Expand<Args...>::print(); // �ݹ�չ��ʣ�������
////    }
////};
////
////// �ݹ���ֹ����
////template<typename Last>
////struct Expand<Last>
////{
////    static void print() {
////        std::cout << typeid(Last).name() << std::endl;
////    }
////};
//
//////ǰ������
////template <typename... Args>
////class Expend;
////
//////չ������������ֹ����
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
//////չ������������ֹ����
////template <>
////class Expend<> 
////{
////public:
////    Expend() {}
////};
////
//////��������ݹ�չ��������
////template <typename T, typename... Args>
////class Expend<T, Args...> 
////{
////public:
////    Expend(T value, Args... args) 
////    {
////        std::cout << value << std::endl;
////        Expend<Args...> e(args...); //�ݹ����
////    }
////};
//
////���������չ������������ֹ����
//template <typename... Args>
//class Expend 
//{    
//};
//
////չ�����������ػ��汾
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
//    // ����һ��ģ�������������int��double��char��������
//    //Expand<int, double, char>::print();
//
//    Expend<int, double, std::string, char> e(1, 2.5, "HeavenBurn", 'c');
//
//    return 0;
//}

////�����������С
//template <typename ...Args>	//ģ�������
//void ShowSize(Args... args)	//�����ββ�����
//{
//	std::cout << sizeof...(args) << std::endl;	//sizeof...�����������ѯ�������е�Ԫ�ظ���
//}
//
////�ݹ�չ��������
////չ��������ֹ����
////template <typename T>
////void ShowParameterPack(const T& value)
////{
////	std::cout << value << std::endl;
////}
////
//////��ֹ����Ҳ�������޲ε�
////void ShowParameterPack()
////{
////	std::cout << std::endl;
////}
////
//////������չ������
////template <typename T, typename ...Args>
////void ShowParameterPack(T value, Args... args)
////{
////	std::cout << value << " ";
////	ShowParameterPack(args...);
////}
//
////����Ϊ��ʱ����
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
//////ʹ�ö��ű��ʽչ��������
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
//////��ʹ�ö��ű��ʽ
////template<class T>
////int PrintArg(const T& value)
////{
////	std::cout << value << " ";
////	return 0;
////}
//////չ������
////template<class ...Args>
////void ShowParameterPack(Args... args)
////{
////	int arr[] = { PrintArg(args)... }; //�б��ʼ��
////	std::cout << std::endl;
////}
//
//int main()
//{
//	ShowSize(1, 'j', 4.0);
//	//ShowParameterPack(1, 'j', "CL");
//	ShowParameterPack([](auto value) {std::cout << value << " "; return 0; } , 1, 'j', "CL");
//}