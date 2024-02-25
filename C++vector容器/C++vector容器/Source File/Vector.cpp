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
		inline T* allocate_memory(size_t size);
		void _Resize(const size_t new_size, const T& t);
	public:
		Vector();
		Vector(size_t capacity);
		~Vector();
		void push_back(const T& data);
		inline void pop_back();
		inline size_t size() const;
		inline size_t capacity() const;
		//void show() const;
		void reserve(size_t new_cap);
		inline void resize(const size_t new_cap);
		inline void resize(const size_t new_size, const T& T);
		inline T& at(size_t index) const;

		inline T& operator[](const int index);
	};


	//释放内存函数
	template <typename T>
	void Vector<T>::deallocate_memory()	
	{
		for (int i = 0; i < m_Capacity; ++i) {
			m_Data[i].~T(); // 手动调用析构函数
		}
		::operator delete(m_Data);	//释放内存
		m_Data = nullptr;
	}


	//手动分配函数
	template <typename T>
	inline T* Vector<T>::allocate_memory(size_t size)	
	{
		return static_cast<T*>(::operator new(sizeof(T) * size));
	}



	//默认构造
	template <typename T>	
	Vector<T>::Vector()
		:m_Data(nullptr), m_Size(0), m_Capacity(0)
	{}


	//有参支持没有默认构造函数的类,将分配内存和构造元素分开处理
	template <typename T>
	Vector<T>::Vector(size_t capacity)
		: m_Size(0), m_Capacity(0)
	{
		m_Data = allocate_memory(capacity);	//使用全局new分配内存
		if (!m_Data) {
			return;
		}
	}


	//析构函数
	template <typename T>
	Vector<T>::~Vector()
	{
		if (m_Data) {
			deallocate_memory();
		}
	}


	//尾端插入
	template <typename T>
	void Vector<T>::push_back(const T& value)
	{
		if (m_Size >= m_Capacity) {
			m_Capacity = m_Capacity == 0 ? 1 : m_Capacity * 2;
			T* data = allocate_memory(m_Capacity);
			if (!data) {
				return;
			}
			for (int i = 0; i < m_Size; i++) {
				new (data + i) T(m_Data[i]);
			}
			if (m_Data) {
				deallocate_memory();
			}
			m_Data = data;
			data = nullptr;
		}
		new(m_Data + m_Size) T(value);
		m_Size++;
	}


	//尾端弹出
	template <typename T>
	inline void Vector<T>::pop_back()
	{
		if (m_Size > 0) {
			m_Size--;
		}
	}


	//返回元素个数
	template <typename T>
	inline size_t Vector<T>::size() const
	{
		return m_Size;
	}


	//返回容量
	template <typename T>
	inline size_t Vector<T>::capacity() const
	{
		return m_Capacity;
	}


	//reserve函数只会分配内存，不会构造新元素
	template <typename T>
	void Vector<T>::reserve(const size_t new_cap)
	{
		if (m_Capacity < new_cap) {	//当新容量大于原容量时，扩大vector容器
			m_Capacity = new_cap;
		}
		else {
			return;	//反之，reserve函数什么都不做
		}
		T* data = allocate_memory(m_Capacity);	//只手动分配新内存
		if (!data) {
			return;
		}
		for (int i = 0; i < m_Size; i++) {
			new (data + i) T(m_Data[i]);	//手动调用构造
		}
		if (m_Data) {
			deallocate_memory();
		}
		m_Data = data;
		data = nullptr;
	}


	//resize函数在变大vector时不仅分配新内存，还会构造新元素，
	//因此resize有重载函数，重载后无默认构造的类型也可使用。
	template <typename T>
	void Vector<T>::_Resize(const size_t new_size, const T& t)
	{
		if (new_size <= m_Size) {	//若小于等于原size，则丢弃多出的部分
		}
		else if (new_size <= m_Capacity) {	//若在原size和capacity之间，不扩大，但调用构造函数构造新元素
			for (size_t i = m_Size; i < m_Capacity; i++) {
				m_Data[i] = t;
			}
		}
		else {	//若比原capacity大，扩容
			m_Capacity = new_size;
			T* data = new T[m_Capacity];
			if (!data) {
				return;
			}
			for (size_t i = 0; i < m_Size; i++) {
				data[i] = m_Data[i];
			}
			for (size_t i = m_Size; i < m_Capacity; i++) {
				data[i] = t;
			}
			if (m_Data) {
				deallocate_memory();
			}
			m_Data = data;
			data = nullptr;
		}
		m_Size = new_size;
	}

	//使用默认构造改变大小
	template <typename T>
	inline void Vector<T>::resize(const size_t new_size)
	{
		_Resize(new_size, T());
	}

	//使用非默认构造改变大小
	template <typename T>
	inline void Vector<T>::resize(const size_t new_size, const T& t)
	{
		_Resize(new_size, t);
	}


	//返回index处的引用，index从0开始
	template <typename T>
	inline T& Vector<T>::at(size_t index) const
	{
		if (0 > index || index >= m_Size) {
			throw std::out_of_range("out of range");
		}
		return m_Data[index];
	}


	
	//重载[]
	template <typename T>
	inline T& Vector<T>::operator[](const int index)
	{
		return m_Data[index];
	}

}
