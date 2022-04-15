//1.简单工厂模式
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void show() {}
};

class SubA : public Base
{
public:
	void show()
	{
		cout << "I am SubA" << endl;
	}
};

class SubB : public Base
{
public:
	void show()
	{
		cout << "I am SubB" << endl;
	}
};

class SimpleFactory
{
public:
	static Base* CreateCar(int id);
};


Base* SimpleFactory::CreateCar(int id)
{
	switch (id)
	{
	case 1:
		return new SubA();
		break;
	case 2:
		return new SubB();
		break;
	}
}


int main()
{
	SimpleFactory* fc = new SimpleFactory();
	Base* car1 = fc->CreateCar(1);
	Base* car2 = fc->CreateCar(2);
	car1->show();
	car2->show();

	return 0;
}