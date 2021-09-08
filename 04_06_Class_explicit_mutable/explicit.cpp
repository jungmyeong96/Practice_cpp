#include <iostream>

class MyString {
	private:
//	char * string_content;
//	int string_length;
//	int change;
//	int memory_capacity;
	mutable int datas;//const 함수 안에서 해당 멤버 변수에 const 가 아닌 작업을 할 수 있게 만들어줍니다.

	public:
//	explicit MyString(int capacity); //명시적으로 정확한 파라미터를 검사

	//MyString(const char a);
	//MyString(const char *str);
	//MyString(const MyString& str);
	MyString(int data);

//	~MyString();

	//int length() const;
	void DoSomething(int x) const;	
	void PrintData() const;

};

MyString::MyString(int data)
{
	datas = data;
}

void MyString::DoSomething(int x) const {
		datas = x;
}

void MyString::PrintData() const {
	std::cout << "data: " << datas << std::endl; 
}

/*
MyString::MyString(const MyString& str)
{
  string_length = str.string_length;
  memory_capacity = string_length;
  string_content = new char[string_length];

  for (int i = 0; i != string_length; i++)
    string_content[i] = str.string_content[i];
}

MyString::MyString(int capacity) {
  string_content = new char[capacity];
  string_length = 0;
  memory_capacity = capacity;
  std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
  string_length = 0;
  while (str[string_length++]) {
  }
  string_content = new char[string_length];
  memory_capacity = string_length;

  for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
*/
int main()
{
	//MyString s(3);
	MyString A(10);

	A.DoSomething(3);
	A.PrintData();
}
