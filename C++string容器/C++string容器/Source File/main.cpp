
//string��ȡ�Ӵ�
#include <string>
#include <iostream>

int main()
{
	std::string email("danshenmiao@outlook.com");
	int pos = email.find('@');
	std::string username = email.substr(0, pos);
	std::cout << username << std::endl;
}

////** ׷�Ӻ���ԭ�ͣ�**
////
////* `string& operator+=(const char* str); `                   //����+=������
////* `string& operator+=(const char c); `                         //����+=������
////* `string& operator+=(const string& str); `                //����+=������
////* `string& append(const char* s); `                               //���ַ���s���ӵ���ǰ�ַ�����β
////* `string& append(const char* s, int n); `                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
////* `string& append(const string& s); `                           //ͬoperator+=(const string& str)
////* `string& append(const string& s, int pos, int n); `/ / �ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
//
//#include <string>
//#include <iostream>
//
//int main()
//{
//	//* `string& operator+=(const char* str); `                   //����+=������
//	std::string str1("Little");
//	str1 += "Buster";
//
//	//* `string& operator+=(const char c); `                         //����+=������
//	std::string str2("Air");
//	str2 += ':';
//
//	//* `string& operator+=(const string& str); `                //����+=������
//	std::string str3("Thousands of years of inheritance");
//	str2 += str3;
//
//	//* `string& append(const char* s); `                               //���ַ���s���ӵ���ǰ�ַ�����β
//	std::string str4("U");
//	str4.append("-ena");
//	
//	//* `string& append(const char* s, int n); `                 //���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
//	str4.append("air hanavi", 5);
//
//	//* `string& append(const string& s); `                           //ͬoperator+=(const string& str)
//	std::string str5("asd");
//	str5.append(str4);
//
//	//* `string& append(const string& s, int pos, int n); `/ / �ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
//	str1.append(str2, 0, 3);	//pos���㿪ʼ
//	std::cout << str1 << std::endl;
//
//}

////��ֵ�ĺ���ԭ�ͣ�
////
////* `string& operator=(const char* s); `             //char*�����ַ��� ��ֵ����ǰ���ַ���
////* `string& operator=(const string& s); `         //���ַ���s������ǰ���ַ���
////* `string& operator=(char c); `                          //�ַ���ֵ����ǰ���ַ���
////* `string& assign(const char* s); `                  //���ַ���s������ǰ���ַ���
////* `string& assign(const char* s, int n); `     //���ַ���s��ǰn���ַ�������ǰ���ַ���
////* `string& assign(const string& s); `              //���ַ���s������ǰ�ַ���
////* `string& assign(int n, char c); `                  //��n���ַ�c������ǰ�ַ���
//#include <string>
//#include <iostream>
//
//int main()
//{
//	//* `string& operator=(const char* s); `             //char*�����ַ��� ��ֵ����ǰ���ַ���
//	std::string str1;
//	str1 = "CLANNAD";
//
//	//* `string& operator=(const string& s); `         //���ַ���s������ǰ���ַ���
//	std::string str2;
//	str2 = str1;
//
//	//* `string& operator=(char c); `                          //�ַ���ֵ����ǰ���ַ���
//	//�����ڴ����ַ���ʱ�͸�ֵ�ַ�	std::string str3 = 'a'//error
//	std::string str3;
//	str3 = 'a';
//
//	//* `string& assign(const char* s); `                  //���ַ���s������ǰ���ַ���
//	std::string str4;
//	str4.assign("CLANNAD");
//
//	//* `string& assign(const char* s, int n); `     //���ַ���s��ǰn���ַ�������ǰ���ַ���
//	std::string str5;
//	str5.assign("CLANNAD", 4);
//	std::cout << str5 << std::endl;
//
//	//* `string& assign(const string& s); `              //���ַ���s������ǰ�ַ���
//	std::string str6;
//	str6.assign(str5);
//	std::cout << str6 << std::endl;
//
//
//	//* `string& assign(int n, char c); `                  //��n���ַ�c������ǰ�ַ���
//	std::string str7;
//	str7.assign(6, '6');
//	std::cout << str7 << std::endl;
//
//}

//#include <string>
//#include <iostream>
// 
////���캯��ԭ�ͣ�
////
////string();	//����һ���յ��ַ���
////string(const char* s);	//ʹ���ַ���s��ʼ��
////string(const char* s, int n);	//ʹ���ַ���sǰn���ַ����г�ʼ��
////string(const string& str);	 //ʹ��һ��string�����ʼ����һ��string����
////string(int n, char c);	//ʹ��n���ַ�c��ʼ��
//
//int main()
//{
//	//Ĭ�Ϲ���
//	std::string str1;
//
//	//ʹ���ַ�����ʼ��
//	const char* c = "CLANNAD";
//	std::string str2(c);
//	std::string str3("CLANNAD");
//	std::string str31("CLANNAD", 4);
//	std::cout << str31 << std::endl;
//
//	//��������
//	std::string str4(str3);
//
//	//ʹ��n���ַ���ʼ��
//	std::string str5(4, 'T');
//}