#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <utility>

const unsigned int INITIAL_CAPACITY = 4;

template <class T>
class MyVector {
private:
	T* data;
	unsigned int size;
	unsigned int capacity;

	void free() noexcept;

	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other) noexcept;

	void resize(const unsigned int newCapacity);

public:
	MyVector<T>();
	
	MyVector<T>(const MyVector<T>& other);
	MyVector<T>(MyVector<T>&& other) noexcept;

	MyVector<T>& operator=(const MyVector<T>& other);
	MyVector<T>& operator=(MyVector<T>&& other) noexcept;

	void addElement(const T& element);

	T& operator[](const unsigned int index);
	T operator[](const unsigned int index) const;

	unsigned int getSize() const;

	template <class R>
	MyVector<T>& apply(R(*func)(T&));

	~MyVector<T>();
};

template<class T>
void MyVector<T>::free() noexcept {
	if (data != nullptr) {
		delete[] data;
	}
}

template<class T>
void MyVector<T>::copyFrom(const MyVector<T>& other) {
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];
	for (unsigned int index = 0; index < size; ++index) {
		data[index] = other.data[index];
	}
}

template<class T>
void MyVector<T>::moveFrom(MyVector<T>&& other) noexcept {
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
}

template<class T>
void MyVector<T>::resize(const unsigned int newCapacity) {
	if (newCapacity < size) {
		return;
	}

	capacity = newCapacity;

	T* resizedData = new T[capacity];
	for (unsigned int index = 0; index < size; ++index) {
		resizedData[index] = data[index];
	}

	free();
	data = resizedData;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<class T>
void MyVector<T>::addElement(const T& element) {
	if (size == capacity) {
		resize(capacity << 1);
	}

	data[size] = element;
	++size;
}

template<class T>
T& MyVector<T>::operator[](const unsigned int index) {
	if (index >= size) {
		throw "Index out of bounds!";
	}

	return data[index];
}

template<class T>
T MyVector<T>::operator[](const unsigned int index) const {
	if (index >= size) {
		throw "Index out of bounds!";
	}

	return data[index];
}

template<class T>
unsigned int MyVector<T>::getSize() const {
	return size;
}

template<class T>
MyVector<T>::MyVector() : size(0), capacity(INITIAL_CAPACITY) {
	data = new T[capacity];
}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& other) {
	copyFrom(other);
}

template<class T>
MyVector<T>::MyVector(MyVector<T>&& other) noexcept {
	moveFrom(std::move(other));
}

template<class T>
template<class R>
MyVector<T>& MyVector<T>::apply(R(*func)(T&)) {
	for (unsigned int index = 0; index < size; ++index) {
		func(data[index]);
	}

	return *this;
}

template<class T>
MyVector<T>::~MyVector() {
	free();
}

#endif // !MY_VECTOR_H
