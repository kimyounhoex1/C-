#include <iostream>
#include <cstring>

class Marin {
private:
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;
  char* name;
public:
  Marin();
  Marin(int x, int y, const char* marin_name);
  ~Marin();

  int attack();
  void be_attacked(int damage_earn);
  void move(int x, int y);

  void show_status();
};

Marin::Marin() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}

Marin::Marin(int x, int y, const char* marin_name) {
  name = new char[strlen(marin_name) + 1];
  name = strcpy(name, marin_name);
  hp = 50;
  coord_x = x;
  coord_y = y;
  damage = 5;
  is_dead = false;
}

int Marin::attack(){
  return damage;
}
void Marin::be_attacked(int damage_earn){
  hp = hp-damage_earn;
  if(hp <= 0) {
    is_dead = true;
  }
}
void Marin::move(int x, int y){
  coord_x -= x;
  coord_y -= y;
}

void Marin::show_status(){
  std::cout << " *** Marine " << name << " *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

Marin::~Marin() {
  std::cout << name << " 의 소멸자 호출! " << std::endl;
  if(name != NULL) {
    delete[] name;
  }
}

int main() {
  Marin *marins[100];

  marins[0] = new Marin(1, 2, "my");
  marins[1] = new Marin(2, 3, "marin");

  marins[0]->show_status();
  marins[1]->show_status();

  std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;

  marins[1]->be_attacked(marins[0]->attack());

  marins[0]->show_status();
  marins[1]->show_status();

  delete marins[0];
  delete marins[1];
}