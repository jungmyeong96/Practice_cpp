#include <iostream>
#include <string.h>

class mystring
{
	private:
		//static int len;
		int len;
		char c;
		char *str_;
	public:
		mystring(char c);
		mystring(const char *str);
		mystring(const mystring& str);
		~mystring();

		void put_str() const;
		int length() const;//내부 멤버변수 바꾸지 않을 시 항상 상
		static	int str_len(const char *str);

		mystring& assign(const mystring& str);
		mystring& assign(const char * str);


	//	void str_cat(char *str1, char *str2);
	//	char *str_charset(char *str, char *chset);
	//	char *str_same(char *str1, char *str2);
	//	char *str_cmp(char *str1, char *str2);
};

mystring::mystring(char c)
{
	str_ = new char[1];
	str_[0] = c;
	len = 1;
}

mystring::mystring(const char *str)
{
	len = mystring::str_len(str);
	str_ = new char[len];
	for (int i = 0;i < len;i++)
		str_[i] = str[i];
}

mystring::mystring(const mystring& str)
{
  len = str.len;
  str_ = new char[len];
  for (int i = 0; i < len; i++)
    str_[i] = str.str_[i];
}

mystring::~mystring()
{
	delete[] str_;
}

int mystring::length() const
{
	return (len);
}

void mystring::put_str() const
{
	std::cout << str_ << std::endl;
}

int mystring::str_len(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

mystring& mystring::assign(const char *str)
{
	int str_len = mystring::str_len(str);
	if (str_len > len)
	{
		delete[] str_;
		str_ = new char[str_len];
	}
	for(int i = 0;i < str_len;i++)
		str_[i] = str[i];
	len = str_len;
	return *this;
}

mystring& mystring::assign(const mystring& str)
{
	if (str.len > len)
	{
		delete[] str_;
		str_ = new char[str.len];
	}
	for(int i = 0;i < str.len;i++)
		str_[i] = str.str_[i];
	len = str.len;
	return *this;
}

int main()
{
	mystring str_func1("asdfsdfds");
	mystring str_func2('a');
	mystring str_func3(str_func2);

	str_func1.put_str();
	str_func2.put_str();
	str_func3.put_str();

	str_func1.assign("abcde");
	str_func2.assign(str_func1);
	
	str_func1.put_str();
	str_func2.put_str();
}//assign 처음부터 다시할것 복사생성자 할당체크