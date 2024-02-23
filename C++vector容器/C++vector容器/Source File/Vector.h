#ifndef __VECTOR__H__
#define __VECTOR__H__

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

	public:
		Vector();
		Vector(size_t capacity);
		~Vector();
		void push_back(const T& data);
		void pop_back();
		size_t size() const;
		size_t capacity() const;
		void show() const;
		void reserve(size_t new_cap);

		T& operator[](const int index);
	};

	template <typename T>	//默认构造
	Vector<T>::Vector()
		:m_Data(nullptr), m_Size(0), m_Capacity(0)
	{}

	//有参支持没有默认构造函数的类,将分配内存和构造元素分开处理
	template <typename T>
	Vector<T>::Vector(size_t capacity)	
		:m_Size(0), m_Capacity(0)
	{
		m_Data = static_cast<T*>(::operator new(sizeof(T) * capacity));	//先使用全局new分配内存
		if (!m_Data) {
			return;
		}
		for (int i = 0; i < capacity; ++i) {
			new (m_Data + i) T(); //再使用placement new手动构造元素
		}
	}

	//析构函数
	template <typename T>
	Vector<T>::~Vector()
	{
		if (m_Data) {
			for (int i = 0; i < m_Capacity; ++i) {
				m_Data[i].~T(); // 手动调用析构函数
			}
			::operator delete(m_Data);
			m_Data = nullptr;
		}
	}

	template <typename T>
	void Vector<T>::push_back(const T& value)
	{
		if (m_Size < m_Capacity) {
			m_Data[m_Size] = value;
			m_Size++;
			return;
		}
		else if (m_Capacity == 0) {
			m_Capacity++;
		}
		else {
			m_Capacity *= 2;
		}
		T* data = static_cast<T*>(::operator new(sizeof(T) * m_Capacity));	//分配内存
		if (!data) {
			return;
		}
		for (int i = 0; i < m_Capacity; i++) {
			new (data + i) T(); //使用placement new手动构造元素
		}
		for (int i = 0; i < m_Size; i++) {
			data[i] = m_Data[i];	//复制元素
		}
		data[m_Size] = value;
		m_Size++;
		if (m_Data) {
			for (int i = 0; i < m_Capacity; ++i) {
				m_Data[i].~T(); // 手动调用析构函数
			}
			::operator delete(m_Data);
			m_Data = nullptr;
		}
		m_Data = data;
		data = nullptr;
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

	template <typename T>
	void Vector<T>::show() const
	{
		std::cout << "capacity" << m_Capacity << std::endl;
		std::cout << "size" << m_Size << std::endl;
		for (int i = 0; i < m_Size; i++) {
			std::cout << m_Data[i] << " ";
		}
		std::cout << std::endl;
	}

	template <typename T>
	void Vector<T>::reserve(size_t new_cap)
	{
		if (m_Capacity < new_cap) {
			m_Capacity = new_cap;
		}
		else {
			return;
		}
		T* data = static_cast<>
		for (int i = 0; i < m_Size; i++) {
			data[i] = m_Data[i];
		}
		if (m_Data) {
			delete[] m_Data;
			m_Data = nullptr;
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

#endif // !__VECTOR__H__

