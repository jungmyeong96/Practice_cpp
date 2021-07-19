#include <iostream>

class Date
{
	private:
		int	year;
		int	month;
		int	day;
	public:
		void	setdate(int y, int m, int d)
		{
			year = y;
			month = m;
			day = d;
		}
		//void	addday(int inc);
	//	void	addmonth(int inc);
	//	void	addyear(int inc);

		void	showdate()
		{
			std::cout << "year : " << year << std::endl;
			std::cout << "month : " << month << std::endl;
			std::cout << "day : " << day << std::endl;
		}
};

int main()
{
	int y;
	int m;
	int d;
	Date date;

	std::cout << "year : " ;
	std::cin >> y ;
	std::cout << "month : ";
	std::cin >> m ;
	std::cout << "day : ";
	std::cin >> d ;

	date.setdate(y, m, d);

	date.showdate();
	return (0);
}
