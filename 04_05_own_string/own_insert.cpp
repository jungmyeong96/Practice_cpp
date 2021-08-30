#include <iostream>
#include <string.h>


class MyString
{
	private:
	char * string_content;
	int		string_length;
	int		memory_capacity;

	public:
	MyString(char c);
	MyString(const char *str);
	MyString(const MyString& str);
	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int a);
	void	print() const;
	void	println() const;
	char	at(int i) const;
	MyString& MyString::insert(int loc, const MyString& str);
	MyString& MyString::insert(int loc, const char* str);
	MyString& MyString::insert(int loc, char c);
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
};

MyString::MyString(char c)
{
	string_length = 1;
	memory_capacity = string_length;
	string_content = new char[1];
	string_content[0] = c;
}

MyString::MyString(const char *str)
{
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for(int i= 0; i < string_length; i++)
		string_content[i] = str[i];
}

MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	memory_capacity = string_length;
	string_content = new char[string_length];

	for(int i = 0; i < string_length; i++)
	{
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString()
{
	delete[] string_content;
}

MyString& MyString::assign(const MyString& str)
{
	if (this->memory_capacity < str.string_length)
	{
		delete[] string_content;

		this->string_content = new char[str.string_length];
		this->memory_capacity = str.string_length;
	}
	this->string_length = str.string_length;
	for (int i = 0; i < this->string_length; i++)
		this->string_content[i] = str.string_content[i];
	return *this;
}

MyString& MyString::assign(const char* str)
{
	int str_length = strlen(str);
	if (this->memory_capacity < str_length)
	{
		delete[] string_content;

		this->string_content = new char[str_length];
		this->memory_capacity = str_length;
	}
	this->string_length = strlen(str);
	for (int i = 0; i < this->string_length; i++)
		this->string_content[i] = str[i];
	return *this;
}


int MyString::length() const { return string_length; }

int	MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size)
{
	if (this->memory_capacity < size)
	{
		char *temp = this->string_content;
	
		this->memory_capacity = size;
		this->string_content = new char[size];

		for(int i = 0; i < size; i++)
			this->string_content[i] = temp[i];
		delete[] temp;
	}
}

char MyString::at(int i) const 
{
	if (i >= string_length || i < 0)
		return 0;
	else
		return string_content[i];
}

void MyString::print() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}

void MyString::println() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
  std::cout << std::endl;
}

int main() {
  MyString str1("very very very long string");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  std::cout << "String offset : " << str1.at(6) << std::endl;
  str1.println();
}
