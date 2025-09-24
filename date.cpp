#include <iostream>


class Date {
  int year_;
  int month_;
  int day_;
  int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
  // Date() = default;
  Date(){
    std::cout << "기본 생성자 호출!" << std::endl;
    year_ = 2025;
    month_ = 9;
    day_ = 22;
  }

  Date(int year, int month, int day){
    std::cout << "인자 3개인 생성자 호출!" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);
  bool IsYoun();
  
  int GetCurrentMonthTotalDays(int year, int month);
  int MakeDate();
  void ShowDate();
};


void Date::SetDate(int year, int month, int date){
  year_ = year;
  month_ = month;
  day_ = date;
  MakeDate();
};

void Date::AddDay(int inc){
  day_ += inc;
  while(day_ > date[month_-1]){
    day_ -= date[month_-1];
    AddMonth(1);
  }
};
void Date::AddMonth(int inc){
  month_ += inc;
  if(month_ >= 13) {
    AddYear(1);
    month_ = 1;
  }
};
void Date::AddYear(int inc){
  year_+=inc;
  if(IsYoun()) {
    date[1] = 29;
  } else {
    date[1] = 28;
  }
};

bool Date::IsYoun(){
  return (year_ % 4 == 0) && (year_%100 != 0);  
}

int Date::GetCurrentMonthTotalDays(int year, int month){
  if(month != 2) {
    return date[month-1];
  } else if (IsYoun()){
    return 29;
  } else {
    return 28;
  }
}

int Date::MakeDate(){
  if(IsYoun()){
    date[1] = 29;
  } else {
    date[1] = 28;
  }
};

void Date::ShowDate(){
  std::cout << year_ << "년 " << month_ << " 월" << day_ << " 일" << std::endl;
};



int main(){
  Date day;
  Date day2(2012, 10, 31);
  day.ShowDate();
  day2.ShowDate();
  return 0;
}