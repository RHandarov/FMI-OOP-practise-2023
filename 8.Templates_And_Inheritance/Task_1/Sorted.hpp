#ifndef SORTED_H
#define SORTED_H

#include <utility>
#include <iostream>
#include <stdexcept>

template <typename T>
inline void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
class Sorted {
private:
	T* data;
	unsigned int size;
	unsigned int capacity;

	void copyFrom(const Sorted<T>& other);
	void moveFrom(Sorted<T>&& other);

	void resize(unsigned int newCapacity);

	void putLastElementInPlace();
	void shiftElementToTheEnd(unsigned int index);

	int getIndex(const T& element) const;

	void freeMemory();

public:
	Sorted();

	Sorted(const Sorted<T>& other);
	Sorted<T>& operator=(const Sorted<T>& other);

	Sorted(Sorted<T>&& other);
	Sorted<T>& operator=(Sorted<T>&& other);

	//returns reference to itself to achieve chain calling
	Sorted<T>& add(const T& element);
	Sorted<T>& remove(const T& element);
	void print() const;

	~Sorted();
};

template<typename T>
void Sorted<T>::copyFrom(const Sorted<T>& other) {
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];
	for (unsigned int index = 0; index < size; ++index) {
		data[index] = other.data[index];
	}
}

template<typename T>
void Sorted<T>::moveFrom(Sorted<T>&& other) {
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
}

template<typename T>
void Sorted<T>::resize(unsigned int newCapacity) {
	if (newCapacity < size) {
		return;
	}

	capacity = newCapacity;

	T* buffer = new T[capacity];
	for (unsigned int index = 0; index < size; ++index) {
		buffer[index] = data[index];
	}

	freeMemory();
	data = buffer;
}

template<typename T>
void Sorted<T>::putLastElementInPlace() {
	for (unsigned int index = size - 1; index > 0; --index) {
		if (data[index - 1] > data[index]) {
			swap(data[index - 1], data[index]);
		} else {
			break;
		}
	}
}

template<typename T>
void Sorted<T>::shiftElementToTheEnd(unsigned int position) {
	for (unsigned int index = position; index < size - 1; ++index) {
		swap(data[index], data[index + 1]);
	}
}

template<typename T>
int Sorted<T>::getIndex(const T& element) const {
	unsigned int low = 0, high = size - 1;

	while (low <= high) {
		unsigned int middle = (low + high) >> 1;

		if (data[middle] == element) {
			return middle;
		} else if (data[middle] < element) {
			low = middle + 1;
		} else {
			high = middle - 1;
		}
	}

	return -1;
}

template<typename T>
inline void Sorted<T>::freeMemory() {
	delete[] data;
}

template<typename T>
inline Sorted<T>::Sorted() : size(0), capacity(4), data(new T[4]) {
}

template<typename T>
inline Sorted<T>::Sorted(const Sorted<T>& other) {
	copyFrom(other);
}

template<typename T>
Sorted<T>& Sorted<T>::operator=(const Sorted<T>& other) {
	if (this != &other) {
		freeMemory();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Sorted<T>::Sorted(Sorted<T>&& other) {
	moveFrom(std::move(other));
}

template<typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T>&& other) {
	if (this != &other) {
		freeMemory();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
Sorted<T>& Sorted<T>::add(const T& element) {
	if (size == capacity) {
		resize(capacity << 1);
	}

	++size;
	data[size - 1] = element;

	putLastElementInPlace();

	return *this;
}

template<typename T>
Sorted<T>& Sorted<T>::remove(const T& element) {
	unsigned int elementPosition = getIndex(element);

	if (elementPosition == -1) {
		throw std::exception("This element is not in the array!");
	}

	shiftElementToTheEnd(elementPosition);
	--size;

	if ((size << 1) < capacity && capacity > 4) {
		resize(capacity >> 1); //it is for saving memory
	}

	return *this;
}

template<typename T>
void Sorted<T>::print() const {
	for (unsigned int index = 0; index < size; ++index) {
		std::cout << data[index] << std::endl;
	}
}

template<typename T>
inline Sorted<T>::~Sorted() {
	freeMemory();
}

#endif // !SORTED_H
