#include <iostream>

namespace mystl
{
	template <typename T>
	class Vector
	{
	private:
		T* m_Data;
		size_t m_Size;
		size_t m_Capacity;

	private:
		void deallocate_memory();
		T* allocate_memory(size_t size);
	public:
		Vector();
		Vector(size_t capacity);
		~Vector();
		void push_back(const T& data);
		void pop_back();
		size_t size() const;
		size_t capacity() const;
		//void show() const;
		void reserve(size_t new_cap);

		T& operator[](const int index);
	};

	//�ͷ��ڴ溯��
	template <typename T>
	void Vector<T>::deallocate_memory()	
	{
		for (int i = 0; i < m_Capacity; ++i) {
			m_Data[i].~T(); // �ֶ�������������
		}
		::operator delete(m_Data);
		m_Data = nullptr;
	}

	//�ֶ����亯��
	template <typename T>
	T* Vector<T>::allocate_memory(size_t size)	
	{
		return static_cast<T*>(::operator new(sizeof(T) * size));
	}


	//Ĭ�Ϲ���
	template <typename T>	
	Vector<T>::Vector()
		:m_Data(nullptr), m_Size(0), m_Capacity(0)
	{}

	//�в�֧��û��Ĭ�Ϲ��캯������,�������ڴ�͹���Ԫ�طֿ�����
	template <typename T>
	Vector<T>::Vector(size_t capacity)
		: m_Size(0), m_Capacity(0)
	{
		m_Data = allocate_memory();	//ʹ��ȫ��new�����ڴ�
		if (!m_Data) {
			return;
		}
	}

	//��������
	template <typename T>
	Vector<T>::~Vector()
	{
		if (m_Data) {
			deallocate_memory();
		}
	}

	template <typename T>
	void Vector<T>::push_back(const T& value)
	{
		if (m_Size >= m_Capacity) {
			m_Capacity = m_Capacity == 0 ? 1 : m_Capacity * 2;
			T* data = allocate_memory(m_Capacity);
			for (int i = 0; i < m_Size; i++) {
				new (data + i)T(m_Data[i]);
			}
			deallocate_memory();
			m_Data = data;
			data = nullptr;
		}
		new(m_Data + m_Size) T(value);
		m_Size++;
	}

	template <typename T>
	void Vector<T>::pop_back()
	{
		if (m_Size > 0) {
			m_Size--;
		}
	}

	template <typename T>
	size_t Vector<T>::size() const
	{
		return m_Size;
	}

	template <typename T>
	size_t Vector<T>::capacity() const
	{
		return m_Capacity;
	}

	//template <typename T>
	//void Vector<T>::show() const
	//{
	//	std::cout << "capacity" << m_Capacity << std::endl;
	//	std::cout << "size" << m_Size << std::endl;
	//	for (int i = 0; i < m_Size; i++) {
	//		std::cout << m_Data[i] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	template <typename T>
	void Vector<T>::reserve(size_t new_cap)
	{
		if (m_Capacity < new_cap) {
			m_Capacity = new_cap;
		}
		else {
			return;
		}
		T* data = allocate_memory(m_Capacity);
		if (!data) {
			return;
		}
		for (int i = 0; i < m_Capacity; i++) {
			new (data + i)T();	//�ֶ�����
		}
		for (int i = 0; i < m_Size; i++) {
			data[i] = m_Data[i];
		}
		if (m_Data) {
			deallocate_memory();
		}
		m_Data = data;
		data = nullptr;
	}


	template <typename T>
	T& Vector<T>::operator[](const int index)
	{
		return m_Data[index];
	}

}
