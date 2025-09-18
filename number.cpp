#include <iostream>

int main() {
  int lucy_number = 3;
  std::cout << "내 비밀 수를 맞추어 보세요 ~" << std::endl;

  int user_input;
  while(1) {
    std::cout << "입력 : ";
    std::cin >> user_input;
    if(user_input != lucy_number) {
      std::cout << "다시 생각해보세요~" << std::endl;
    } else {
      std::cout << "맞추셨습니다~~" << std::endl;
      break; 
    }
  }
}