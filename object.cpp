#include <iostream>

void print(char c){
  std::cout << "char : " << c << std::endl;
};
void print(int i){
  std::cout << "int : " << i << std::endl;
};

int main(){
  int a = 10;
  char c = 'c';
  double d = 3.14f;

  print(a);
  print(c);
  print(d);
}