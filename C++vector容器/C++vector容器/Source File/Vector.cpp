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
		//对迭代器没有深入了解，粗糙的实现,反向的先不做了
		class iterator
		{
		private:
			T* m_pointer;

		public:
			iterator()
				:m_pointer(nullptr) {}
			iterator(T* pointer)
				:m_pointer(pointer) {}
			~iterator() {}

			//成员函数
			//解引用，vs还做了检测
			inline T& operator*() const
			{
				return *m_pointer;
			}

			inline T& operator->() const
			{
				return m_pointer;
			}

			//前置加加,vs还进行了判断不知道是干啥的
			inline iterator& operator++()
			{
				++m_pointer;
				return *this;
			}

			//后置加加
			inline iterator operator++(int)
			{
				iterator tmp = *this;
				++(*this);
				return tmp;
			}

			inline iterator& operator--()
			{
				--m_pointer;
				return *this;
			}

			//后置加加
			inline iterator operator--(int)
			{
				iterator tmp = *this;
				--(*this);
				return tmp;
			}

			inline iterator& operator+=(const int i)
			{
				m_pointer += i;
				return *this;
			}

			//迭代器加某个数
			inline iterator operator+(const int i) const
			{
				iterator tmp = *this;
				tmp += i;
				return tmp;
			}

			inline iterator& operator-=(const int i)
			{
				return *this += -i;
			}

			inline iterator operator-(const int i) const
			{
				iterator tmp = *this;
				tmp -= i;
				return tmp;
			}

			//计算两个迭代器之间的距离
			inline __int64 operator-(const iterator& right) const
			{
				return m_pointer - right.m_pointer;
			}

			inline T& operator[](const int i) const
			{
				return *(*this + i);
			}

			inline bool operator==(const iterator& right) const
			{
				return this->m_pointer == right.m_pointer;
			}

			inline bool operator!=(const iterator& right) const
			{
				return !(*this == right);
			}

			inline bool operator<(const iterator& right) const
			{
				return this->m_pointer < right.m_pointer;
			}

			inline bool operator>(const iterator& right) const
			{
				return right < *this;
			}

			inline bool operator<=(const iterator& right) const
			{
				return !(right < *this);
			}

			inline bool operator>=(const iterator& right) const
			{
				return !(*this < right);
			}
		};

	private:
		void deallocate_memory();
		inline T* allocate_memory(size_t size);
		void _Resize(const size_t new_size, const T& t);

	public:
		//成员函数
		Vector();
		Vector(size_t capacity);
		~Vector();
		void push_back(const T& data);
		inline void pop_back();
		inline size_t size() const;
		inline size_t capacity() const;
		void reserve(size_t new_cap);
		inline void resize(const size_t new_cap);
		inline void resize(const size_t new_size, const T& T);
		inline T& at(size_t index) const;
		inline bool empty() const;
		inline void clear();
		inline iterator begin();
		inline iterator end();
		inline iterator insert(Vector::iterator pos, const T& value);
		inline iterator insert(Vector::iterator pos, size_t num, const T& value);



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


	//vs是使用指针判断
	template <typename T>
	inline bool Vector<T>::empty() const
	{
		return m_Size == 0;
	}


	//vs通过指针实现，可能还会销毁数据，并无效化迭代器，我不知怎么处理
	template <typename T>
	inline void Vector<T>::clear()
	{
		m_Size = 0;
	}


	//返回第一个元素的位置
	template <typename T>
	typename inline Vector<T>::iterator Vector<T>::begin()	//typename告诉编译器iterator是一个类型而不是变量
	{
		return Vector<T>::iterator(m_Data);
	}


	//返回最后一个元素的后一个位置
	template <typename T>
	typename inline Vector<T>::iterator Vector<T>::end()
	{
		return Vector<T>::iterator(m_Data + m_Size);
	}

	
	//插入一个value
	template <typename T>
	typename inline Vector<T>::iterator Vector<T>::insert(Vector::iterator pos, const T& value)
	{
		return insert(pos, 1, value);
	}

	//插入num个value
	template <typename T>
	typename inline Vector<T>::iterator Vector<T>::insert(Vector::iterator pos, size_t num, const T& value)
	{
		if (pos < begin() || pos >= end()) {
			throw std::out_of_range("out of range");
		}
		size_t size = static_cast<size_t>(pos - begin());
		if (m_Capacity >= m_Size + num) {	//插入后无需扩容
			if (num == 0) {
				return Vector<T>::iterator(m_Data + size);
			}
			for (size_t i = m_Size; i > size; i--) {	//pos后的元素后移
				m_Data[i + num - 1] = m_Data[i - 1];
			}
			for (size_t i = 0; i < num; i++) {
				m_Data[size + i] = value;
			}
			m_Size += num;
		}
		else {	//插入后需要扩容
			while (m_Capacity < m_Size + num) {	//扩容
				m_Capacity = m_Capacity == 0 ? 1 : m_Capacity * 2;
			}
			T* data = new T[m_Capacity];
			if (!data) {
				exit(EXIT_FAILURE);
			}
			if (size > 0) {

			}
			for (size_t i = 0; i < size - 1 && size > 0; i++) {	//拷贝pos之前的数据
				data[i] = m_Data[i];
			}
			for (size_t i = size == 0 ? 0 : size - 1; i < size + num; i++) {	//拷贝传入的数据
				data[i] = value;
			}
			for (size_t i = size + num; i < m_Capacity; i++) {	//拷贝pos之后的数据
				data[i] = m_Data[i - num];
			}
			if (m_Data) {
				deallocate_memory();
			}
			m_Data = data;
			data = nullptr;
			m_Size += num;
		}
		return Vector<T>::iterator(m_Data + size);
	}


	//重载[]
	template <typename T>
	inline T& Vector<T>::operator[](const int index)
	{
		return m_Data[index];
	}

}
