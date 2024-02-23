
//string获取子串
#include <string>
#include <iostream>

int main()
{
	std::string email("danshenmiao@outlook.com");
	int pos = email.find('@');
	std::string username = email.substr(0, pos);
	std::cout << username << std::endl;
}

////** 追加函数原型：**
////
////* `string& operator+=(const char* str); `                   //重载+=操作符
////* `string& operator+=(const char c); `                         //重载+=操作符
////* `string& operator+=(const string& str); `                //重载+=操作符
////* `string& append(const char* s); `                               //把字符串s连接到当前字符串结尾
////* `string& append(const char* s, int n); `                 //把字符串s的前n个字符连接到当前字符串结尾
////* `string& append(const string& s); `                           //同operator+=(const string& str)
////* `string& append(const string& s, int pos, int n); `/ / 字符串s中从pos开始的n个字符连接到字符串结尾
//
//#include <string>
//#include <iostream>
//
//int main()
//{
//	//* `string& operator+=(const char* str); `                   //重载+=操作符
//	std::string str1("Little");
//	str1 += "Buster";
//
//	//* `string& operator+=(const char c); `                         //重载+=操作符
//	std::string str2("Air");
//	str2 += ':';
//
//	//* `string& operator+=(const string& str); `                //重载+=操作符
//	std::string str3("Thousands of years of inheritance");
//	str2 += str3;
//
//	//* `string& append(const char* s); `                               //把字符串s连接到当前字符串结尾
//	std::string str4("U");
//	str4.append("-ena");
//	
//	//* `string& append(const char* s, int n); `                 //把字符串s的前n个字符连接到当前字符串结尾
//	str4.append("air hanavi", 5);
//
//	//* `string& append(const string& s); `                           //同operator+=(const string& str)
//	std::string str5("asd");
//	str5.append(str4);
//
//	//* `string& append(const string& s, int pos, int n); `/ / 字符串s中从pos开始的n个字符连接到字符串结尾
//	str1.append(str2, 0, 3);	//pos从零开始
//	std::cout << str1 << std::endl;
//
//}

////赋值的函数原型：
////
////* `string& operator=(const char* s); `             //char*类型字符串 赋值给当前的字符串
////* `string& operator=(const string& s); `         //把字符串s赋给当前的字符串
////* `string& operator=(char c); `                          //字符赋值给当前的字符串
////* `string& assign(const char* s); `                  //把字符串s赋给当前的字符串
////* `string& assign(const char* s, int n); `     //把字符串s的前n个字符赋给当前的字符串
////* `string& assign(const string& s); `              //把字符串s赋给当前字符串
////* `string& assign(int n, char c); `                  //用n个字符c赋给当前字符串
//#include <string>
//#include <iostream>
//
//int main()
//{
//	//* `string& operator=(const char* s); `             //char*类型字符串 赋值给当前的字符串
//	std::string str1;
//	str1 = "CLANNAD";
//
//	//* `string& operator=(const string& s); `         //把字符串s赋给当前的字符串
//	std::string str2;
//	str2 = str1;
//
//	//* `string& operator=(char c); `                          //字符赋值给当前的字符串
//	//不能在创建字符串时就赋值字符	std::string str3 = 'a'//error
//	std::string str3;
//	str3 = 'a';
//
//	//* `string& assign(const char* s); `                  //把字符串s赋给当前的字符串
//	std::string str4;
//	str4.assign("CLANNAD");
//
//	//* `string& assign(const char* s, int n); `     //把字符串s的前n个字符赋给当前的字符串
//	std::string str5;
//	str5.assign("CLANNAD", 4);
//	std::cout << str5 << std::endl;
//
//	//* `string& assign(const string& s); `              //把字符串s赋给当前字符串
//	std::string str6;
//	str6.assign(str5);
//	std::cout << str6 << std::endl;
//
//
//	//* `string& assign(int n, char c); `                  //用n个字符c赋给当前字符串
//	std::string str7;
//	str7.assign(6, '6');
//	std::cout << str7 << std::endl;
//
//}

//#include <string>
//#include <iostream>
// 
////构造函数原型：
////
////string();	//创建一个空的字符串
////string(const char* s);	//使用字符串s初始化
////string(const char* s, int n);	//使用字符串s前n个字符进行初始化
////string(const string& str);	 //使用一个string对象初始化另一个string对象
////string(int n, char c);	//使用n个字符c初始化
//
//int main()
//{
//	//默认构造
//	std::string str1;
//
//	//使用字符串初始化
//	const char* c = "CLANNAD";
//	std::string str2(c);
//	std::string str3("CLANNAD");
//	std::string str31("CLANNAD", 4);
//	std::cout << str31 << std::endl;
//
//	//拷贝构造
//	std::string str4(str3);
//
//	//使用n个字符初始化
//	std::string str5(4, 'T');
//}