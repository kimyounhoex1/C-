#include <iostream>
#include <cstring>

class Marin {
private:
  static int total_marin_num;
  const static int i = 0;

  int hp;
  int coord_x, coord_y;
  const int default_damage;
  bool is_dead;
  char* name;
public:
  Marin();
  Marin(int x, int y);
  Marin(int x, int y, int default_damage);
  Marin(int x, int y, const char* marin_name);
  ~Marin();

  int attack() const;
  Marin& be_attacked(int damage_earn);
  Marin be_attacked_mm(int damage_earn);
  void move(int x, int y);

  void show_status();
  static void show_total_marin();

};
int Marin::total_marin_num = 0;

Marin::Marin() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  name = new char[strlen("null") + 1];
  name = strcpy(name, "null");
  total_marin_num++;
}

Marin::Marin(int x, int y) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
  name = new char[strlen("null") + 1];
  name = strcpy(name, "null");

  total_marin_num++;
}

Marin::Marin(int x, int y, int default_damage) : hp(50), coord_x(x), coord_y(y), default_damage(default_damage), is_dead(false) {
  name = new char[strlen("null") + 1];
  name = strcpy(name, "null");
  
  total_marin_num++;
}

Marin::Marin(int x, int y, const char* marin_name) : hp(50), coord_x(x), coord_y(y), default_damage(5), is_dead(false) {
  name = new char[strlen(marin_name) + 1];
  name = strcpy(name, marin_name);
  
  total_marin_num++;
}

int Marin::attack() const{
  return default_damage;
}

Marin& Marin::be_attacked(int damage_earn){
  hp -= damage_earn;
  if(hp <= 0) is_dead = true;

  return *this;
}

Marin Marin::be_attacked_mm(int damage_earn){
  this->hp -= damage_earn;
  if(this->hp <= 0) this->is_dead = true;

  return *this;
}

void Marin::move(int x, int y){
  coord_x -= x;
  coord_y -= y;
}

void Marin::show_status(){
  std::cout << " *** Marine " << name << " *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << "현재 총 마린 수 : " << total_marin_num << std::endl;
}

Marin::~Marin() {
  std::cout << name << " 의 소멸자 호출! " << std::endl;
  if(name != NULL) {
    delete[] name;
  }
  total_marin_num--;
}

void create_marin() {
  Marin marin(1, 2);
  marin.show_status();
}

void Marin::show_total_marin(){
  std::cout << "전체 마린 수: " << total_marin_num << std::endl;
}
// 다른거 하는중

int main() {
  Marin marin1(2, 3, 5);
  marin1.show_status();

  Marin marin2(3, 5, 10);
  marin2.show_status();

  std::cout << std::endl << "마린 1이 마린 2를 두 번 공격" << std::endl;
  marin2.be_attacked(marin1.attack()).be_attacked(marin1.attack());

  marin1.show_status();
  marin2.show_status();
}