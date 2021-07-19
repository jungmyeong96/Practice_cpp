#include <iostream>

class Animal {//설계도 역할을 하는 클래스
 private://접근지시자(외부 접근차단)
  int food; //인스턴스 변수 == 멤버변수
  int weight;

 public: //접근지시자(외부 접근허용)
  void set_animal(int _food, int _weight) {//인스턴스 메소드수== 멤버함수
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
  }
};  // 세미콜론 잊지 말자!

int main() {
  Animal animal;//Animal class의 animal instance
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_stat();
  return 0;
}
