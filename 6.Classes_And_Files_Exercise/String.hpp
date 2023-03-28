#ifndef STRING_H
#define STRING_H

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

	~String();
};

#endif // !STRING_H