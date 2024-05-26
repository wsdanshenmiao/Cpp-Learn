#include <iostream>
#include <string>
#include <list>

template <typename T,
		template <typename U>
			typename Container>
class XCls
{
private:
	Container<T> c;
};

template <typename T>
using Lst = std::list<T, std::allocator<T>>;

int main()
{
	//XCls<std::string, std::list> x1;
	XCls<std::string, Lst> x1;
}


//template <typename T>
//class example
//{};
//
//template <typename T>
//class example<T*>
//{};

//class Entity 
//{
//public:
//    int m_X;
//    int m_Y;
//    Entity(int x, int y)
//        :m_X(x), m_Y(y) {}
//    void Function() {}
//};
//
//template <typename T>
//struct Less 
//{
//    constexpr bool operator()(const T& _Left, const T& _Right) const
//    {
//        return _Left < _Right;
//    }
//};
//
//template <>
//struct Less<Entity>
//{
//    constexpr bool operator()(const Entity& _Left, const Entity& _Right) const
//    {
//        if (_Left.m_X != _Right.m_X) {
//            return _Left.m_X < _Right.m_X;
//        }
//        else {
//            return _Left.m_Y < _Right.m_Y;
//        }
//    }
//};
//
//
//int main()
//{
//    std::cout << Less<int>()(9, 3);
//    std::cout << Less<Entity>()(Entity(3, 4), Entity(6, 8));
//}

//int main()
//{
//	Entity<int>(1, 1);
//}
//
////#include <string>
////
//////类模板中成员函数类外实现
////template<typename T>
////class Entity {
////public:
////	T m_X;
////	T m_Y;
////	//成员函数类内声明
////	Entity(T x, T y);
////	void Function();
////};
////
//////构造函数 类外实现
////template<typename T>
////Entity<T>::Entity(T x, T y)
////	:m_X(x),m_Y(y){}
////
//////成员函数 类外实现
////template<typename T>
////void Entity<T>::Function()
////{
////}
////
////int main()
////{
////	Entity<double> p(1.0, 1.0);
////	p.Function();
////}
//
////#include <iostream>
////
////template<typename T>
////class Entity
////{
////public:
////	T m_X,m_Y;
////};
////
////class Player1 :public Entity<int> //必须指定一个类型
////{
////};
////void test01()
////{
////	Player1 c;
////}
////
//////类模板继承类模板 ,可以用T2指定父类中的T类型
////template<class T1, class T2>
////class Player2 :public Entity<T2>
////{
////public:
////	Player2()
////	{
////		std::cout << typeid(T1).name() << std::endl;
////		std::cout << typeid(T2).name() << std::endl;
////	}
////};
////
////void test02()
////{
////	Player2<int, char> child1;
////}
////
////
////int main() {
////
////	test01();
////
////	test02();
////
////	return 0;
////}
//
////template<class T = int>
////class Entity
////{
////public:
////	T m_X, m_Y;
////	Entity(T x, T y)
////		:m_X(x), m_Y(y){}
////};
////
////int main()
////{
////
////}
//
////#include <iostream>
////using namespace std;
////
////class Entity
////{
////public:
////	int m_X,m_Y;
////
////	Entity(int x,int y)
////		:m_X(x),m_Y(y){}
////};
////
//////普通函数模板
////template<class T>
////bool myCompare(T& a, T& b)
////{
////	if (a == b){
////		return true;
////	}
////	else{
////		return false;
////	}
////}
////
//////具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
//////具体化优先于常规模板
////template<> bool myCompare(Entity& e1, Entity& e2)
////{
////	if (e1.m_X == e2.m_X && e1.m_Y == e2.m_Y)
////	{
////		return true;
////	}
////	else{
////		return false;
////	}
////}
////
////void test01()
////{
////	int a = 10;
////	int b = 20;
////	//内置数据类型可以直接使用通用的函数模板
////	bool ret = myCompare(a, b);
////	if (ret)
////	{
////		cout << "a == b " << endl;
////	}
////	else
////	{
////		cout << "a != b " << endl;
////	}
////}
////
////void test02()
////{
////	Entity e1(20, 10);
////	Entity e2(20, 10);
////	//自定义数据类型，不会调用普通的函数模板
////	//可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
////	bool ret = myCompare(e1, e2);
////	if (ret){
////		cout << "e1 == e2 " << endl;
////	}
////	else{
////		cout << "e1 != e2 " << endl;
////	}
////}
////
////int main() {
////
////	test01();
////
////	test02();
////
////	system("pause");
////
////	return 0;
////}
//
////template<typename T, int N>
////class Array
////{
////private:
////	T Array[N];
////
////public:
////	int GetSize() { return N; }
////};
////
////int main()
////{
////	Array<int, 10> array;
////	std::cout << array.GetSize() << std::endl;
////}
//
////template<typename X>	
////void Print(X value)
////{
////	std::cout << value << std::endl;
////}
////
////int main()
////{
////	Print(5);
////	Print("CLANNAD");
////}