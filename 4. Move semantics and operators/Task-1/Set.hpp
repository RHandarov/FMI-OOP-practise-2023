#ifndef SET_H
#define SET_H

class Set {
private:
	int* elements;

	unsigned int numElements;
	unsigned int capacity;

	unsigned int calculateCurrentCapacity() const;
	bool shouldResize() const;
	void resize();

	void copy(const int* elements, const unsigned int numElements);

	int getIndex(const int element) const;
public:
	Set();
	Set(const Set& other);

	Set(Set&& other);

	Set& operator=(const Set& other);
	Set& operator=(Set&& other);

	Set operator+(const Set& other) const;
	Set& operator+=(const Set& other);

	Set operator+(const int addNumber) const;
	friend Set operator+(const int addNumber, const Set& set);

	Set operator*(const int number) const;
	friend Set operator*(const int number, const Set& set);

	Set operator/(const Set& other) const;
	Set& operator/=(const Set& other);

	~Set();

	bool addElement(const int element);
	bool deleteElement(const int element);
	Set& setUnion(const Set& other);
	void setIntersection(const Set& other);

	void print() const;
};

#endif // !SET_H
