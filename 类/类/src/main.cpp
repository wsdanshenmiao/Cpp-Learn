#include <iostream>

class Player
{
public:	//����Ȩ��

	int x, y;
	int speed;	//����

	void Move(int ax, int ay)	//��Ϊ
	{
		x += ax * speed;
		y += ay * speed;
	}
};
int main()
{
	Player player1;	//ʹ����ʵ����һ������
}