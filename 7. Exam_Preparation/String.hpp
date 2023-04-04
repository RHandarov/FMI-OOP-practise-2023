#ifndef STRING_H
#define STRING_H

#include <ostream>

class String {
private:
	char* data;
	unsigned int size;
	unsigned int capacity;

	void free();

	void setString(const char* newData);

	void moveFrom(String&& other);

public:
	String();
	String(const char* string);

	String(const String& other);
	String(String&& other);

	String& operator=(const String& other);
	String& operator=(String&& other);

	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	~String();
};

#endif // !STRING_H