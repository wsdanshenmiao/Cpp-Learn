#include <iostream>
#include <vector>

//动态数组的使用优化
class Location
{
public:
	int x, y;
	Location(int x, int y)
		:x(x), y(y)
	{}
	Location(const Location& l)
		:x(l.x), y(l.y)
	{
		std::cout << "copy" << std::endl;
	}
};

int main()
{
	std::vector<Location> location;
	location.reserve(3);
	location.emplace_back(1, 2);
	location.push_back(Location(3,4));
	location.push_back(Location(5,6));
}

////动态数组
//class Location
//{
//public:
//	int x, y;
//};
//
//std::ostream& operator <<(std::ostream & stream, const Location& l)
//{
//	stream << l.x << "," << l.y;
//	return stream;
//}
//
//int main()
//{
//	std::vector<Location> l;	//创建一个动态数组
//	l.push_back({ 1,2 });	//用push_back给数组赋值
//	l.push_back({ 3,4 });
//	l.push_back({ 5,6 });
//	for (int i = 0; i < l.size(); i++) {
//		std::cout << l[i] << std::endl;
//	}
//	//l.clear();	//清除数组
//	l.erase(l.begin() + 1);	//删除某个元素
//	//基于range的for循环
//	for (Location& l : l) {
//		std::cout << l << std::endl;
//	}
//}