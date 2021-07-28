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
		void put_str() const;
	//	char *mkcstr(char c);
	//	char *mkstrstr(char *str);
		int length() const;//내부 멤버변수 바꾸지 않을 시 항상 상
		static	int str_len(const char *str);
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

int main()
{
	mystring str_func1('a');
	mystring str_func2("test");
	mystring str_func3(str_func2);

	str_func1.put_str();
	str_func2.put_str();
	str_func3.put_str();
}
