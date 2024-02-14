#ifndef __MYARRAY__HPP__
#define __MYARRAY__HPP__

//创建通用数组类模板
template<typename T>
class MyArray
{
private:
	T* m_Array;
	size_t m_Capacity;	//数组容量
	size_t m_Elements;	//数组元素个数

public:
	//有参构造函数
	MyArray(size_t capacity)
		:m_Capacity(capacity)
	{
		m_Array = new T[capacity];
		m_Elements = 0;
	}

	//拷贝构造	防止浅拷贝
	MyArray(const MyArray& arr)
		:m_Capacity(arr.m_Capacity), m_Elements(arr.m_Elements)
	{
		m_Array = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Elements; i++) {
			m_Array[i] = arr.m_Array[i];
		}
	}

	void PushData(const T& value)
	{
		if (m_Elements >= m_Capacity) {
			return;
		}
		m_Array[m_Elements] = value;
		m_Elements++;
	}

	void PopData()
	{
		if (0 < m_Elements && m_Elements <= m_Capacity) {
			m_Elements--;
		}
		return;
	}

	T& operator[](int index)
	{
		return m_Array[index];
	}

	size_t GetCapacity()
	{
		return m_Capacity;
	}

	size_t GetElements()
	{
		return m_Elements;
	}

	//重载operater=	防止浅拷贝
	MyArray& operator=(const MyArray& arr)
	{
		if (m_Array) {	//删除原有数据
			delete[] m_Array;
			m_Array = nullptr;
			m_Capacity = 0;
			m_Elements = 0;
		}
		m_Capacity = arr.m_Capacity;
		m_Elements = arr.m_Elements;
		m_Array = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Elements; i++) {
			m_Array[i] = arr.m_Array[i];
		}
		return *this;
	}

	//析构函数
	~MyArray()
	{
		if (m_Array) {
			delete[] m_Array;
			m_Array = nullptr;
		}
	}
};

#endif // !__MYARRAY__HPP__