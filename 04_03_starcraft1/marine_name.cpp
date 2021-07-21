#include <iostream>
#include <string.h>

class Marine
{
	private:
	char *name_;
	int hp;
	int coord_x, coord_y;
	int damage;
	bool is_dead;

	public: //생성자
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, const char *name);
	~Marine();

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);
	void show_status();
};

Marine::Marine()
{
	name_ = NULL;
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y)
{
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y, const char *name)
{
	name_ = new char[strlen(name) + 1];
	strcpy(name_, name);

	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
}

Marine::~Marine() 
{
  std::cout << name_ << " 의 소멸자 호출 ! " << std::endl;
  if (name_ != NULL) 
    delete[] name_;
}

void	Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}

int	Marine::attack()
{
	std::cout << std::endl << name_ << " 이";
	return damage;
}

void	Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if (hp <= 0)
		is_dead = true;
	std::cout << name_ <<" 를 공격" << std::endl;
}

void	Marine::show_status()
{
	std::cout << "*** Marine ***" << std::endl;
	std::cout << "Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << " HP : " << hp << std::endl;
}

int	main()
{
	/*객체 포인터 배열*/
	Marine* marines[2];

	marines[0] = new Marine(2 ,3 ,"Marine 1");
	marines[1] = new Marine(3, 5, "Marine 2");

	marines[0]->show_status();
	marines[1]->show_status();

	marines[1]->be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];
}
