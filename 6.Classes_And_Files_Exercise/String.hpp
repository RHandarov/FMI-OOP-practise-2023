#ifndef STRING_H
#define STRING_H

#include <iostream>

const unsigned int MIN_CAPACITY = 10;

class String {
private:
	char* data;
	unsigned int size;
	unsigned int capacity;

	void freeMemory();

	void setData(const char* data);
	void setSize(unsigned int size);
	void setCapacity();

	void resize();

	void copy(const String& other);
	void copy(const char* data);

	void move(String&& other);

	String& append(const char* data);

public:
	String(const char* data = "");
	String(const String& other);
	String(String&& other);

	String& operator=(const char* data);
	String& operator=(const String& other);
	String& operator=(String&& other);

	char operator[](unsigned int index) const;

	String operator+(const String& other) const;
	String operator+(const char* data) const;
	friend String operator+(const char* leftHandSide, const String& rightHandSide);

	bool operator==(const String& other) const;
	bool operator==(const char* other) const;
	friend bool operator==(const char* leftHandSide, const String& rightHandSide);

	bool operator!=(const String& other) const;
	bool operator!=(const char* other) const;
	friend bool operator!=(const char* leftHandSide, const String& rightHandSide);

	bool operator<=(const String& other) const;
	bool operator<=(const char* other) const;
	friend bool operator<=(const char* leftHandSide, const String& rightHandSide);

	bool operator<(const String& other) const;
	bool operator<(const char* other) const;
	friend bool operator<(const char* leftHandSide, const String& rightHandSide);

	bool operator>(const String& other) const;
	bool operator>(const char* other) const;
	friend bool operator>(const char* leftHandSide, const String& rightHandSide);

	bool operator>=(const String& other) const;
	bool operator>=(const char* other) const;
	friend bool operator>=(const char* leftHandSide, const String& rightHandSide);

	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	unsigned int length() const;
	bool empty() const;

	const char* c_str() const;

	~String();
};

#endif // !STRING_H