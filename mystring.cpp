#include <iostream>
#include <cstring>

class MyString {
  char* string_content; // 문자 포인터
  int string_length; // 문자 길이
  int memory_capacity; // 현재 할당된 용량
public:
  MyString(char c);
  MyString(const char* str);
  MyString(const MyString& str);
  ~MyString();

  int length() const;
  char* content() const;
  int capacity() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);

  MyString& concat(MyString str);
  bool contain(MyString& str);
  bool equals(MyString& str);
  bool compSize(MyString& str);
  char* toString();
  void reserve(int size);
  char at(int i) const;
  MyString& insert(int loc, const MyString& str);
  MyString& insert(int loc, const char* str);
  MyString& insert(int loc, char c);

  void print() const;
  void println() const;
};

MyString::MyString(char c){
  string_content = new char[2];
  string_content[0] = c;
  string_content[1] = '\0';
  // *string_content = c;
  string_length = 1;
  memory_capacity = 2;
}

MyString::MyString(const char *str){
  string_length = strlen(str);
  string_content = new char[string_length+1];
  for(int i = 0; i<string_length; i++) {
    string_content[i] = str[i];
  }
  string_content[string_length] = '\0';
  memory_capacity = string_length + 1;
}

MyString::MyString(const MyString& str){
  string_length = str.string_length;
  memory_capacity = str.memory_capacity;
  string_content = new char[string_length];
  for(int i = 0; i < string_length; i++) {
    string_content[i] = str.string_content[i];
  }
  
}

MyString::~MyString() {
  delete[] string_content;
}

int MyString::length() const {
  return string_length;
}

char* MyString::content() const {
  return string_content;
}

MyString& MyString::concat(MyString str){
  char* temp = new char[str.length() + string_length];

  memcpy(temp, string_content, string_length);
  memcpy(temp+string_length, str.content(), str.length());

  delete[] string_content;  

  string_content = temp;
  string_length = str.length()+string_length;
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

bool MyString::contain(MyString &str) {
  int len = str.length();
  for(int i = 0; i< string_length - len; i++) {
    if(*str.content() == string_content[i]){
      for(int j = 0; j < len; j++) {
        if(str.content()[j] != string_content[i+j]) {
          break;
        }
      }
      return true;
    }
  }
  return false;
}

bool MyString::equals(MyString& str) {
  if(str.length() != string_length) {
    return false;
  }
  for(int i = 0; i<string_length; i++){
    if(string_content[i] != str.content()[i]) {
      return false;
    }
  }
  return true;
}

bool MyString::compSize(MyString& str) {
  return true;
  if(str.length() > string_length){

  }
}
void MyString::print() const {
  char* ptr = string_content;
  while(*ptr != '\0') {
    std::cout << *ptr;
    ptr++;
  }
}

void MyString::println() const {
  char* ptr = string_content;
  while(*ptr != '\0') {
    std::cout << *ptr;
    ptr++;
  }
  std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str){
  if(str.length() > memory_capacity){
    delete[] string_content;
    string_content = new char[str.length()];
    memory_capacity = str.string_length;
  }

  for(int i = 0; i<str.string_length; i++){
    *(string_content+i) = *(str.string_content+i);
  }
  string_length = str.string_length;
  
  return *this;
}

MyString& MyString::assign(const char* str){
  int str_length = strlen(str);

  if(str_length > memory_capacity){
    delete[] string_content;
    string_content = new char[str_length];
  }

  for(int i = 0; i<str_length; i++){
    *(string_content+i) = *(str+i);
  }
  string_length = str_length;
  
  return *this;
}

int MyString::capacity() const { return memory_capacity;};

void MyString::reserve(int size) {
  if(size > memory_capacity) {
    char* prev_string_content = string_content;

    string_content = new char[size];
    memory_capacity = size;
    for(int i = 0; i <= string_length; i++){
      string_content[i] = prev_string_content[i];
    }

    delete[] prev_string_content;
  }
}

char MyString::at(int i) const {
  if(i >= string_length || i < 0)
    return NULL;
  else
    return string_content[i];
}

// MyString& MyString::insert(int loc, const MyString& str){
//   if(0 > string_length || string_length < loc) {
//     return *this;
//   }

//   if(string_length + str.string_length > memory_capacity) {
//     memory_capacity = string_length + str.string_length;

//     char* temp_str = str.string_content;
//     string_content = new char[memory_capacity];

//     int index;

//     for(index = 0; index<loc; index++) {
//       string_content[index] = temp_str[index];
//     }
//     for(int j = 0; j <= str.string_length; j++) {
//       string_content[index+j] = str.string_content[j];
//     }
//     for(; index < memory_capacity; index++) {
//       string_content[str.string_length + index] = temp_str[index];
//     }
    
//     delete[] temp_str;

//     string_length = string_length + str.string_length;
//     return *this;
//     }
  
//   for(int i = string_length - 1; i >= loc; i--) {
//     string_content[i+str.string_length] = string_content[i];
//   }

//   for(int i = 0; i<str.string_length; i++) {
//     string_content[i + str.string_length] = string_content[i];
//   }

//   for(int i = 0; i<str.string_length; i++) {
//     string_content[i + loc] = str.string_content[i];
//   }
//   string_length = string_length + str.string_length;
//   return *this;
  
// }

MyString& MyString::insert(int loc, const MyString& str){
  if(loc < 0 && loc > memory_capacity) {
    return *this;
  }

  if(str.string_length + string_length > memory_capacity) {
    char* temp_str = string_content;
    string_content = new char[str.string_length + string_length];
    memory_capacity = str.string_length + string_length;
    size_t index;
    // std::cout << "--------------" << std::endl;
    for(index = 0; index < loc; index++) {
      string_content[index] = temp_str[index];
      // std::cout << index << std::endl;
    }
    // std::cout << "--------------" << std::endl;
    for(int j = 0; j < str.string_length; j++) {
      string_content[index+j] = str.string_content[j];
      // std::cout << index+j << std::endl;
    }
    // std::cout << "--------------" << std::endl;
    for(; index < memory_capacity; index++) {
      string_content[str.string_length+index] = temp_str[index];
      // std::cout << loc + str.string_length+index << std::endl;
    }

    delete[] temp_str;
    string_length = string_length + str.string_length;
    return *this;
  }

  for(int i = string_length-1; i >= loc; i--){
    string_content[i+string_length] = string_content[i];
  }
  for(int i = 0; i<str.string_length; i++) {
    string_content[loc+i] = str.string_content[i];
  }
  string_length = string_length + str.string_length;

  return *this;
}

MyString& MyString::insert(int loc, const char* str){
  MyString temp(str);
  return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c){
  MyString temp(c);
  return insert(loc, temp);
}

int main() {
  // const char* myChar1 = "Hello";
  // const char* myChar2 = " World";
  // const char* myChar3 = "lo";
  // const char* myChar4 = "rrr";

  // MyString *str1 = new MyString(myChar1);
  // MyString *str2 = new MyString(myChar2);
  // MyString *str3 = new MyString(myChar3);
  // MyString *str4 = new MyString(myChar4);

  // std::cout << str1->toString() << std::endl;
  // std::cout << str2->toString() << std::endl;

  // str1->concat(*str2);

  // std::cout << str1->toString() << std::endl;

  // std::cout << str1->contain(*str3) << std::endl;
  // std::cout << str1->contain(*str4) << std::endl;
  
  // MyString str1("very very very long string");
  // str1.reserve(30);
  // std::cout << "Capacity : " << str1.capacity() << std::endl;
  // std::cout << "String length : " << str1.length() << std::endl;
  // str1.println();
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);
  std::cout << "str1 ------------" << std::endl;
  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  std::cout << "str2 ------------" << std::endl;
  std::cout << "Capacity : " << str2.capacity() << std::endl;
  std::cout << "String length : " << str2.length() << std::endl;
  std::cout << "--------------" << std::endl;
  str1.println();
  str1.insert(5, str2);
  str1.println();
  std::cout << "--------------" << std::endl;
}
