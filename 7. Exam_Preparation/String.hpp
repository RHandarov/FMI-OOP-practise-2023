#ifndef STRING_H
#define STRING_H

#include <iostream>

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

	const char* cStr() const;

	String& operator=(const String& other);
	String& operator=(String&& other);

	bool operator==(const String& other) const;

	friend std::istream& operator>>(std::istream& stream, String& string);
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	~String();
};

#endif // !STRING_H