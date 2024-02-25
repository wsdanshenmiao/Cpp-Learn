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


	//�ͷ��ڴ溯��
	template <typename T>
	void Vector<T>::deallocate_memory()	
	{
		for (int i = 0; i < m_Capacity; ++i) {
			m_Data[i].~T(); // �ֶ�������������
		}
		::operator delete(m_Data);	//�ͷ��ڴ�
		m_Data = nullptr;
	}


	//�ֶ����亯��
	template <typename T>
	inline T* Vector<T>::allocate_memory(size_t size)	
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
		m_Data = allocate_memory(capacity);	//ʹ��ȫ��new�����ڴ�
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


	//β�˲���
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


	//β�˵���
	template <typename T>
	inline void Vector<T>::pop_back()
	{
		if (m_Size > 0) {
			m_Size--;
		}
	}


	//����Ԫ�ظ���
	template <typename T>
	inline size_t Vector<T>::size() const
	{
		return m_Size;
	}


	//��������
	template <typename T>
	inline size_t Vector<T>::capacity() const
	{
		return m_Capacity;
	}


	//reserve����ֻ������ڴ棬���ṹ����Ԫ��
	template <typename T>
	void Vector<T>::reserve(const size_t new_cap)
	{
		if (m_Capacity < new_cap) {	//������������ԭ����ʱ������vector����
			m_Capacity = new_cap;
		}
		else {
			return;	//��֮��reserve����ʲô������
		}
		T* data = allocate_memory(m_Capacity);	//ֻ�ֶ��������ڴ�
		if (!data) {
			return;
		}
		for (int i = 0; i < m_Size; i++) {
			new (data + i) T(m_Data[i]);	//�ֶ����ù���
		}
		if (m_Data) {
			deallocate_memory();
		}
		m_Data = data;
		data = nullptr;
	}


	//resize�����ڱ��vectorʱ�����������ڴ棬���ṹ����Ԫ�أ�
	//���resize�����غ��������غ���Ĭ�Ϲ��������Ҳ��ʹ�á�
	template <typename T>
	void Vector<T>::_Resize(const size_t new_size, const T& t)
	{
		if (new_size <= m_Size) {	//��С�ڵ���ԭsize����������Ĳ���
		}
		else if (new_size <= m_Capacity) {	//����ԭsize��capacity֮�䣬�����󣬵����ù��캯��������Ԫ��
			for (size_t i = m_Size; i < m_Capacity; i++) {
				m_Data[i] = t;
			}
		}
		else {	//����ԭcapacity������
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

	//ʹ��Ĭ�Ϲ���ı��С
	template <typename T>
	inline void Vector<T>::resize(const size_t new_size)
	{
		_Resize(new_size, T());
	}

	//ʹ�÷�Ĭ�Ϲ���ı��С
	template <typename T>
	inline void Vector<T>::resize(const size_t new_size, const T& t)
	{
		_Resize(new_size, t);
	}


	//����index�������ã�index��0��ʼ
	template <typename T>
	inline T& Vector<T>::at(size_t index) const
	{
		if (0 > index || index >= m_Size) {
			throw std::out_of_range("out of range");
		}
		return m_Data[index];
	}


	
	//����[]
	template <typename T>
	inline T& Vector<T>::operator[](const int index)
	{
		return m_Data[index];
	}

}
