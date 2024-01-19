#include <iostream>

class Player
{
public:	//访问权限

	int x, y;
	int speed;	//属性

	void Move(int ax, int ay)	//行为
	{
		x += ax * speed;
		y += ay * speed;
	}
};
int main()
{
	Player player1;	//使用类实例化一个对象
}