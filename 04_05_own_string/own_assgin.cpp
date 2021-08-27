#include <iostream>
#include <string.h>


class MyString
{
	private:
	char * string_content;
	int		string_length;

	public:
	MyString(char c);
	MyString(const char *str);
	MyString(const MyString& str);
	~MyString();

	int length() const;
	void	print() const;
	void	printnl() const;
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
};

MyString::MyString(char c)
{
	string_length = 1;
	string_content = new char[1];
	string_content[0] = c;
}

MyString::MyString(const char *str)
{
	string_length = strlen(str);
	string_content = new char[string_length];

	for(int i= 0; i < string_length; i++)
		string_content[i] = str[i];
}

MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
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
	if (this->string_length < str.string_length)
	{
		delete[] string_content;

		this->string_content = new char[str.string_length];
	}
	this->string_length = str.string_length;
	for (int i = 0; i < this->string_length; i++)
		this->string_content[i] = str.string_content[i];
	return *this;
}

MyString& MyString::assign(const char* str)
{
	int str_length = strlen(str);
	if (this->string_length < str_length)
	{
		delete[] string_content;

		this->string_content = new char[str_length];
	}
	this->string_length = strlen(str);
	for (int i = 0; i < this->string_length; i++)
		this->string_content[i] = str[i];
	return *this;
}


int MyString::length() const { return string_length; }

void MyString::print() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
}

void MyString::printnl() const {
  for (int i = 0; i != string_length; i++) {
    std::cout << string_content[i];
  }
  std::cout << std::endl;
}

int main()
{
	MyString str1("1111");
	MyString str2("2222");

	str1.printnl();
	str2.printnl();

	str1.assign("33333333");
	str2.assign("44444444");

	str1.printnl();
	str2.printnl();
}
