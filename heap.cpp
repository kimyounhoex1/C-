#include <iostream>

int main() {
  int a = 4;
  {
    std::cout << "외부의 변수 " << a << std::endl;
    int a = 5;
    std::cout << "내부의 변수 " << a << std::endl;
  } 
  std::cout << "외부의 변수 " << a << std::endl;
}