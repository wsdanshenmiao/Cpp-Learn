

//#include <iostream>
//
//class MyInteger
//{
//private:
//	int m_Num1, m_Num2;
//public:
//	MyInteger()
//		:m_Num1(0),m_Num2(0){}
//	//ǰ��++
//	MyInteger& operator++()	//����Ҫ��������
//	{
//		m_Num1++;
//		m_Num2++;
//		return *this;
//	}
//	//����++,ʹ��ռλ������������
//	MyInteger operator++(int)	//���ܷ������ã���Ϊ���ص��Ǿֲ�����
//	{
//		MyInteger ret = *this;
//		m_Num1++;
//		m_Num2++;
//		return ret;
//	}
//	//ǰ��--
//	MyInteger& operator--()
//	{
//		m_Num1--;
//		m_Num2--;
//		return *this;
//	}
//	MyInteger operator--(int)
//	{
//		MyInteger ret = *this;
//		m_Num1--;
//		m_Num2--;
//		return ret;
//	}
//	friend std::ostream& operator<<(std::ostream& stream, const MyInteger& mint);
//};
//
////�������������
//std::ostream& operator<<(std::ostream& stream, const MyInteger& mint)
//{
//	stream << mint.m_Num1 << " " << mint.m_Num2;
//	return stream;
//}
//
//int main()
//{
//	MyInteger mint;
//	std::cout << mint++ << std::endl;
//	std::cout << ++mint << std::endl;
//	std::cout << --mint << std::endl;
//	std::cout << mint-- << std::endl;
//	std::cout << mint << std::endl;
//}

//#include <iostream>
//
////��������
//class Entity
//{
//private:
//	int m_X, m_Y;
//public:
//	Entity(int x,int y)
//		:m_X(x),m_Y(y){}
//	friend std::ostream& operator<<(std::ostream& stream, Entity& e);
//};
//
//std::ostream& operator<<(std::ostream& stream, Entity& e)
//{
//	stream << e.m_X << " " << e.m_Y;
//	return stream;
//}
//
//int main()
//{
//	Entity e(10, 10);
//	std::cout << e << std::endl;
//}

//#include <iostream>
//
//class Entity
//{
//public:
//	int m_X, m_Y;
//
//	Entity(){}
//	Entity(int x, int y)
//		:m_X(x), m_Y(y){}
//	//��Ա��������
//	//Entity operator+ (Entity& e)
//	//{
//	//	Entity temp;
//	//	temp.m_X = m_X + e.m_X;
//	//	temp.m_Y = m_Y + e.m_Y;
//	//	return temp;
//	//}
//};
//
////ȫ�ֺ�������
////Entity operator+ (Entity& e1,Entity& e2)
////{
////	Entity temp;
////	temp.m_X = e1.m_X + e2.m_X;
////	temp.m_Y = e1.m_Y + e2.m_Y;
////	return temp;
////}
//
//Entity operator+ (Entity& e, int num)
//{
//	Entity temp;
//	temp.m_X = e.m_X + num;
//	temp.m_Y = e.m_Y + num;
//	return temp;
//}
//
//int main()
//{
//	Entity e1(10, 10);
//	Entity e2(20, 20);
//	////��Ա�������ص��ñ���
//	//e1 = e1.operator+(e2);
//	////ȫ�ֺ������ص��ñ���
//	//e1 = operator+(e1, e2);
//	//e1 = e1 + e2;
//	//���������Ҳ���Է�����������
//	e1 = e2 + 20;	//Entity + int
//	std::cout << e1.m_X << e1.m_Y << std::endl;
//}