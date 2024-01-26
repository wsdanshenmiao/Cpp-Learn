#include <iostream>

class String
{
private:
	char* str;
	size_t len;
public:
	String(const char* string)
	{
		len = strlen(string);
		str = new char[len + 1];
		memcpy(str, string, len + 1);
	}
	////Ĭ�ϵĿ������캯��
	//String(const String& string)
	//	:str(string.str), len(string.len) {}
	String(const String& string)
		:len(string.len) {
		str = new char[len + 1];
		memcpy(str, string.str, len + 1);
		std::cout << "copy" << std::endl;
	}
	~String()
	{
		delete[] str;
	}
	char& operator[](size_t num)
	{
		return str[num - 1];
	}
	friend std::ostream& operator<<(std::ostream& stream, const String& string);	//��Ԫ����
};

std::ostream& operator<<(std::ostream& stream, const String& string)	//����������
{
	stream << string.str;
	return stream;
}

void PrintString(const String& string)	//��ʹ�����ã�����´�����
{
	std::cout << string << std::endl;
}

int main()
{
	String string = "CLANNAD";
	String other = string;
	other[1] = 'c';
	PrintString(string);
	PrintString(other);
}