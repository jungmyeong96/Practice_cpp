#include <iostream>
#include <string.h>

class string
{
	private:
		char c;
		char *str_;
	public:
		char *mkcstr(char c);
		char *mkstrstr(char *str);
	//	int str_len(char *str);
	//	char *str_len(char *str1, char *str2);
	//	char *str_charset(char *str, char *chset);
	//	char *str_same(char *str1, char *str2);
	//	char *str_cmp(char *str1, char *str2);
};

char *string::mkcstr(char c)
{
	str_ = new char[2];
	strcpy(str_, &c);
	return (str_);
}

char *string::mkstrstr(char *str)
{
	str_ = new char[strlen(str) + 1];
	strcpy(str_, str);
	return (str_);
}

int main()
{
	string str_func;
	char c;
	char *str1 = "hhh";
	char *str2 = "hoho";

	c = 'a';
	std::cout << str1 << std::endl;
	str1 = str_func.mkcstr(c);
	std::cout << str2 << std::endl;
	str2 = str_func.mkstrstr(str2);
	std::cout << str2 << std::endl;
	
}
