#ifndef SET_H
#define SET_H

class Set {
private:
	int* elements;

	unsigned int numElements;
	unsigned int capacity;

	void resize();
public:
	Set();
	Set(const Set& other);

	Set& operator=(const Set& other);

	~Set();

	bool addElement(const int element);
	bool deleteElement(const int element);
	void setUnion(const Set other);
	void setIntersection(const Set other);

	void print() const;
};

#endif // !SET_H

