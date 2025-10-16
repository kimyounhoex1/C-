#include <iostream>
#include <cstring>

class MyString {
  char* string_content; // 문자 포인터
  int string_length; // 문자 길이
public:
  MyString(char c);
  MyString(const char* str);
  MyString(const MyString& str);
  ~MyString();

  int getLength();
  char* getContent();

  MyString& concat(MyString str);
  
  char* toString();
};

MyString::MyString(char c){
  string_content = new char[2];
  string_content[0] = c;
  string_content[1] = '\0';
  // *string_content = c;
  string_length = 1;
}

MyString::MyString(const char *str){
  string_length = strlen(str);
  string_content = new char[string_length+1];
  for(int i = 0; i<string_length; i++) {
    string_content[i] = str[i];
  }
  string_content[string_length] = '\0';
}

MyString::MyString(const MyString& str){
  string_length = str.string_length;
  string_content = new char[string_length];
  for(int i = 0; i < string_length; i++) {
    string_content[i] = str.string_content[i];
  }
  
}

MyString::~MyString() {
  delete[] string_content;
}

int MyString::getLength() {
  return string_length;
}

char* MyString::getContent() {
  return string_content;
}

MyString& MyString::concat(MyString str){
  char* temp = new char[str.getLength() + string_length];

  memcpy(temp, string_content, string_length);
  memcpy(temp+string_length, str.getContent(), str.getLength());

  delete[] string_content;  

  string_content = temp;
  string_length = str.getLength()+string_length;
  return *this;
}

char* MyString::toString() {
  char* ptr = string_content;
  while(*ptr != '\0') {
    std::cout << *ptr;
    ptr++;
  }

  return ptr;
}

int main() {
  const char* myChar1 = "Hello";
  const char* myChar2 = " World";

  MyString *str1 = new MyString(myChar1);
  MyString *str2 = new MyString(myChar2);

  std::cout << str1->toString() << std::endl;
  std::cout << str2->toString() << std::endl;

  str1->concat(*str2);


  std::cout << str1->toString() << std::endl;
}
