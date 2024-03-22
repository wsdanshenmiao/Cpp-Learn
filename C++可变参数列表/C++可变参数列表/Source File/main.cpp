#include <iostream>

//�����������С
template <typename ...Args>	//ģ�������
void ShowSize(Args... args)	//�����ββ�����
{
	std::cout << sizeof...(args) << std::endl;	//sizeof...�����������ѯ�������е�Ԫ�ظ���
}

//�ݹ�չ��������
//չ��������ֹ����
//template <typename T>
//void ShowParameterPack(const T& value)
//{
//	std::cout << value << std::endl;
//}
//
////��ֹ����Ҳ�������޲ε�
//void ShowParameterPack()
//{
//	std::cout << std::endl;
//}
//
////������չ������
//template <typename T, typename ...Args>
//void ShowParameterPack(T value, Args... args)
//{
//	std::cout << value << " ";
//	ShowParameterPack(args...);
//}

//����Ϊ��ʱ����
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
////ʹ�ö��ű��ʽչ��������
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

////��ʹ�ö��ű��ʽ
//template<class T>
//int PrintArg(const T& value)
//{
//	std::cout << value << " ";
//	return 0;
//}
////չ������
//template<class ...Args>
//void ShowParameterPack(Args... args)
//{
//	int arr[] = { PrintArg(args)... }; //�б��ʼ��
//	std::cout << std::endl;
//}

int main()
{
	ShowSize(1, 'j', 4.0);
	//ShowParameterPack(1, 'j', "CL");
	ShowParameterPack([](auto value) {std::cout << value << " "; return 0; } , 1, 'j', "CL");
}