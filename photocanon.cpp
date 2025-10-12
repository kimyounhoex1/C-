#include <iostream>
#include <cstring>

class Photo_Canon {
  int hp, shield;
  int coord_x, coord_y;
  int damage;
  
  char *name;
  
public:
  Photo_Canon(int x, int y, const char* photo_name);
  // Photo_Canon(const Photo_Canon& pc);
  ~Photo_Canon();


  void show_status();
};

Photo_Canon::Photo_Canon(int x, int y, const char* photo_name){
  std::cout << "생성자 호출! " << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;

  name = new char[strlen(photo_name) + 1];
  strcpy(name, photo_name);
}

// Photo_Canon::Photo_Canon(const Photo_Canon& pc) {
//   hp = pc.hp;
//   shield = pc.shield;
//   damage = pc.damage;
//   coord_x = pc.coord_x;
//   coord_y = pc.coord_y;

//   name = new char[strlen(pc.name) + 1];
//   strcpy(name, pc.name);
// }

// Photo_Canon::Photo_Canon(const Photo_Canon& pc, const char* photo_name){
//   std::cout << "복사 생성자 호출! " << std::endl;
//   hp = pc.hp;
//   shield = pc.shield;
//   damage = pc.damage;
//   coord_x = pc.coord_x;
//   coord_y = pc.coord_y;

//   name = new char[strlen(photo_name) + 1];
//   strcpy(name, photo_name);
// }

Photo_Canon::~Photo_Canon(){
  if(name != NULL) {
    delete [] name;
  }
}

void Photo_Canon::show_status(){
  std::cout << "Photon Cannon " << name << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Photo_Canon pc1(3, 3, "Canon");
  Photo_Canon pc2(pc1);
  Photo_Canon pc3 = pc2;

  pc1.show_status();
  pc2.show_status();
  pc3.show_status();
}