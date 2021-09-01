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
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;
	void reserve(int a);
	void	print() const;
	void	println() const;
	char	at(int i) const;
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	MyString& erase(int loc, int num);
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

MyString& MyString::insert(int loc, const MyString& str)
{
	if (loc < 0 || loc > this->string_length)
		return *this;
	if (this->string_length + str.string_length > memory_capacity)
	{
	  	if (this->memory_capacity * 2 > this->string_length + str.string_length)
			this->memory_capacity *= 2;
   		else
			this->memory_capacity = this->string_length + str.string_length;
		char	*prev_string_content = this->string_content;
		this->string_content = new char[memory_capacity];

		int i;
		for (i = 0; i < loc; i++)
			this->string_content[i] = prev_string_content[i];
		for (int j = 0; j < str.string_length; j++)
			this->string_content[i + j] = str.string_content[j];
		for (; i < this->string_length; i++)
			this->string_content[i + str.string_length] = prev_string_content[i];
		delete[] prev_string_content;
		this->string_length = this->string_length + str.string_length;
		return *this;
	}
	for (int i = this->string_length - 1; i >= loc; i--)
		this->string_content[i + str.string_length] = this->string_content[i];
	for (int i = 0; i < str.string_length; i++)
		this->string_content[i + loc] = str.string_content[i];
	this->string_length = this->string_length + str.string_length;
	return *this;
}

MyString& MyString::insert(int loc, const char* str)
{
	MyString temp(str);
	return (insert(loc, temp));
}
MyString& MyString::insert(int loc, char c)
{
	MyString temp(c);
	return (insert(loc, temp));
}

MyString& MyString::erase(int loc, int num)
{
	if (num < 0 || loc < 0 || loc > this->string_length)// || num > this->string_length)
		return *this;

	if (num >= this->string_length - loc)
	{
		this->string_length = loc;
		return *this;
	}
	for (int i = loc + num; i < this->string_length; i++)
		this->string_content[i - num] = this->string_content[i];
	this->string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const
{
	int i, j;
	if (str.string_length == 0)
		return -1;
	for (i = find_from; i <= this->string_length - str.string_length; i++)
	{
		for (j = 0; j < str.string_length; j++)
		{
			if (this->string_content[i + j] != str.string_content[j])
				break;
		}
	if (j == str.string_length)
		return i;
	}

	return -1;
}

int MyString::find(int find_from, const char *str) const
{
	MyString temp(str);
	return(find(find_from, temp));
}

int MyString::find(int find_from, char c) const
{
	MyString temp(c);
	return(find(find_from, temp));
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
  MyString str1("very");

  str1.erase(2, 1);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  MyString str2("this is a very very long string");

  std::cout << "Location of first <very> in the string : " << str2.find(0, "very")
       << std::endl;
  std::cout << "Location of second <very> in the string : "
       << str2.find(str2.find(0, "very") + 1, "very") << std::endl;

}

