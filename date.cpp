#include <iostream>


class Date {
  int year_;
  int month_;
  int day_;
  int date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
  void SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = date;
  };
  void AddDay(int inc){
    day_ += inc;
    if(day_ > date[month_-1]){
      day_ -= date[month_-1];
      AddMonth(1);
    }
  };
  void AddMonth(int inc){
    month_ += inc;
    if(month_ >= 13) {
      year_++;
      month_ = 1;
    }
  };
  void AddYear(int inc){
    year_+=inc;
    if((year_ % 4 == 0) && (year_%100 != 0)) {
      date[1] = 29;
    } else {
      date[1] = 28;
    }
  };

  void showDate(){
    std::cout << year_ << "년 " << month_ << " 월" << day_ << " 일" << std::endl;
  };
};

int main(){
  Date date;

  date.SetDate(2025, 9, 22);

  date.AddDay(10);

  date.showDate();
}