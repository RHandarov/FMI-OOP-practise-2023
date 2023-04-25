#ifndef PROJECT_H
#define PROJECT_H

class Project {
private:
	char* name;
	unsigned int complexity;

	void free() noexcept;

	void copy(const Project& other);
	void move(Project&& other) noexcept;

	void setName(const char* name);
	void setComplexity(const unsigned int complexity);

public:
	Project(const char* name, const unsigned int complexity);
	Project(const Project& other);
	Project(Project&& other) noexcept;

	const char* getName() const;
	unsigned int getComplexity() const;

	Project& operator=(const Project& other);
	Project& operator=(Project&& other) noexcept;

	~Project();
};

#endif // !PROJECT_H