#include <iostream>
#include <vector>

class Point{
  int x, y;

public:
  Point(int pox_x, int pos_y);
  int GetPointX() const;
  int GetPointY() const;
};

Point::Point(int pos_x, int pos_y) {
  x = pos_x;
  y = pos_y;
};

int Point::GetPointX() const{
  return x;
};
int Point::GetPointY() const{
  return y;
};

class Geometry {
  Point* point_array[100];
  int point_counter;

public:
  Geometry(Point **point_list);
  Geometry();

  void AddPoint(const Point &point);

  // 모든 점들 간의 거리를 출력하는 함수 입니다.
  double GetDistance(const Point &p1, const Point &p2);
  void PrintDistance();

// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
// 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
  std::vector<int> StraightExpr(const Point &p1, const Point& p2);
  long long ccw(const Point& p1, const Point& p2, const Point& p3);
  bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d);
  void PrintNumMeets();
};

Geometry::Geometry(Point **point_list){
  point_counter = 0;
  for(int i = 0; i<100 && point_list[i] !=nullptr; i++){
    point_array[i] = point_list[i];
    point_counter++;
  };
}

Geometry::Geometry(){
  point_counter = 0;
  for(int i = 0; i<100; i++) {
    point_array[i] = nullptr;
  }
};

void Geometry::AddPoint(const Point &point){
  point_array[point_counter++] = new Point(point.GetPointX(), point.GetPointY());
};

double Geometry::GetDistance(const Point &p1, const Point &p2) {
  int DistX = p2.GetPointX() - p1.GetPointX();
  int DistY = p2.GetPointY() - p1.GetPointY();
  return std::sqrt(DistX*DistX + DistY*DistY);
}

void Geometry::PrintDistance(){
  for(int i = 0; i<point_counter; i++){
    for (int j = i+1; j<point_counter; j++) {
      std::cout << GetDistance(*point_array[i], *point_array[j]) << std::endl;;
    }
  }
};

std::vector<int> Geometry::StraightExpr(const Point &p1, const Point& p2){
  std::vector<int> result;
  result.push_back(p2.GetPointX()-p1.GetPointX());
  result.push_back(p2.GetPointX()-p1.GetPointX());
  result.push_back(p1.GetPointX()*p2.GetPointY() - p2.GetPointX()*p1.GetPointY());

  return result;
}

long long Geometry::ccw(const Point& p1, const Point& p2, const Point& p3){
  return ((p2.GetPointX() - p1.GetPointX()) * (p3.GetPointY() - p1.GetPointY()))
          - ((p2.GetPointY() - p1.GetPointY()) * (p3.GetPointX() - p1.GetPointX()));
}

bool Geometry::isIntersect(const Point &a, const Point &b, const Point &c, const Point &d) {
  long long ab = ccw(a, b, c) * ccw(a, b, d);
  long long cd = ccw(c, d, a) * ccw(c, d, b);

  if (ab == 0 && cd == 0) {
        if (std::min(a.GetPointX(), b.GetPointX()) <= std::max(c.GetPointX(), d.GetPointX()) &&
            std::min(c.GetPointX(), d.GetPointX()) <= std::max(a.GetPointX(), b.GetPointX()) &&
            std::min(a.GetPointY(), b.GetPointY()) <= std::max(c.GetPointY(), d.GetPointY()) &&
            std::min(c.GetPointY(), d.GetPointY()) <= std::max(a.GetPointY(), b.GetPointY()))
            return true; // 일직선 위에서 겹침
        return false;
    }
  return (ab <= 0 && cd <= 0);
}

void Geometry::PrintNumMeets() {
    int count = 0;
    // 모든 선분 쌍을 검사
    for (int i = 0; i < point_counter; i++) {
        for (int j = i + 1; j < point_counter; j++) {
            for (int k = i + 1; k < point_counter; k++) {
                for (int l = k + 1; l < point_counter; l++) {
                    if (i == k || i == l || j == k || j == l) continue; // 점이 겹치면 skip
                    if (isIntersect(*point_array[i], *point_array[j], *point_array[k], *point_array[l])) {
                        count++;
                    }
                }
            }
        }
    }
  std::cout << "교차하는 선분 개수: " << count << std::endl;
}

int main() {
    Geometry g;

    // 교차하는 경우 (사각형의 대각선)
    g.AddPoint(Point(0, 0));   // A
    g.AddPoint(Point(4, 0));   // B
    g.AddPoint(Point(0, 4));   // C
    g.AddPoint(Point(4, 4));   // D

    std::cout << "==== 거리 출력 ====" << std::endl;
    g.PrintDistance();

    std::cout << "==== 교차 횟수 출력 ====" << std::endl;
    g.PrintNumMeets(); // (0,0)-(4,4) 와 (4,0)-(0,4) 교차 → 최소 1개

    // 교차하지 않는 경우 (일직선)
    Geometry g2;
    g2.AddPoint(Point(0, 0));
    g2.AddPoint(Point(1, 1));
    g2.AddPoint(Point(2, 2));
    g2.AddPoint(Point(3, 3));

    std::cout << "\n==== g2 거리 출력 ====" << std::endl;
    g2.PrintDistance();

    std::cout << "==== g2 교차 횟수 출력 ====" << std::endl;
    g2.PrintNumMeets(); // 일직선 위 → 교차 없음
}