#include <iostream>

class String
{
public:
	String() = default;
	String(const char* string)
	{
		std::cout << "Created\n";
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	String(const String& string)
	{
		std::cout << "Copy\n";
		m_Size = string.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, string.m_Data, m_Size);
	}
	String(String&& string)
	{
		printf("Move\n");
		m_Size = string.m_Size;
		m_Data = string.m_Data;
		string.m_Data = nullptr;	//·ÀÖ¹ÖØ¸´Îö¹¹
		string.m_Size = 0;
	}
	~String()
	{
		printf("Destroyed\n");
		delete[] m_Data;
	}

	String& operator=(String&& string)
	{
		printf("Move\n");
		if (this != &string) {
			delete[] m_Data;
			m_Size = string.m_Size;
			m_Data = string.m_Data;
			string.m_Data = nullptr;	//·ÀÖ¹ÖØ¸´Îö¹¹
			string.m_Size = 0;
		}
		return *this;
	}

	void Print()
	{
		for (size_t i = 0; i < m_Size; i++) {
			printf("%c", m_Data[i]);
		}
	}

private:
	char* m_Data;
	size_t m_Size;
};

class Entity
{
public:
	Entity(const String& name)
		:m_Name(name) {}
	Entity(String&& name)
		:m_Name(std::move(name)) {}

	void PrintName()
	{
		m_Name.Print();
	}
private:
	String m_Name;
};

int main()
{
	Entity entity(String("dsm"));
	entity.PrintName();
}