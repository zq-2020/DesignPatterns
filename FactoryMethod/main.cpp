//2.工厂方法模式
#include <iostream>
using namespace std;

class carBase
{
public:
	virtual void show() {}
};

class CarA : public carBase
{
public:
	void show()
	{
		cout << "I am CarA" << endl;
	}
};

class CarB : public carBase
{
public:
	void show()
	{
		cout << "I am CarB" << endl;
	}
};

class factoryBase
{
public:
	virtual carBase* createCar() {};
};

class carAfactory : public factoryBase
{
public:
	carBase* createCar()
	{
		return new CarA();
	}
};

class carBfactory : public factoryBase
{
public:
	carBase* createCar()
	{
		return new CarB();
	}
};

int main()
{
	factoryBase* fc1 = new carAfactory();
	factoryBase* fc2 = new carBfactory();
	carBase* carpA = fc1->createCar();
	carBase* carpB = fc2->createCar();
	carpA->show();
	carpB->show();
	return 0;
}