#include <iostream>

class Pay_System
{
public:
	double get_money() const
	{
		// ...
	}
protected:
	void adjust() {}
};

class User_console
{
public:
	virtual ~User_console() = default;
	virtual double get_money() const = 0;
	virtual void adjust() = 0;
};

class Adapter : public User_console, private Pay_System
{
public:
	Adapter() = default;
	double get_money() const
	{
		//using Pay_System::get_money();
	}
	void adjust()
	{
		Pay_System::adjust();
	}
};

int main()
{
	User_console * p = new Adapter();

	p->adjust();

	delete p;

	system("pause");

	return EXIT_SUCCESS;
}
