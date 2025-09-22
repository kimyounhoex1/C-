#include <iostream>


class Date {
  int year_;
  int month_;
  int day_;
  int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
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
    day.SetDate(2011, 3, 1);
    day.ShowDate();
    day.AddDay(30);
    day.ShowDate();
    day.AddDay(2000);
    day.ShowDate();
    day.SetDate(2012, 1, 31); // 윤년
    day.AddDay(29);
    day.ShowDate();
    day.SetDate(2012, 8, 4);
    day.AddDay(2500);
    day.ShowDate();
}