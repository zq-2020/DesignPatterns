//4.原型模式
#include <iostream>

//接口
class CPrototype
{
public:
	CPrototype() {}
	virtual ~CPrototype() {}
	virtual CPrototype* Clone() = 0;
};

//实现
class CConcretePrototype : public CPrototype
{
public:
	CConcretePrototype() :m_counter(100) {}
	virtual ~CConcretePrototype() {}

	//复制自身
	virtual CPrototype* Clone()
	{
		CConcretePrototype* obj = new CConcretePrototype();
		obj->m_counter = this->m_counter;
		return obj;
	}
public:
	int m_counter;
};

int main()
{
	//生成对像
	CPrototype* conProA = new CConcretePrototype();
	//复制自身
	CPrototype* conProB = conProA->Clone();
	std::cout << dynamic_cast<CConcretePrototype*>(conProB)->m_counter << std::endl;
	delete conProA; conProA = NULL;
	delete conProB; conProB = NULL;

	return 0;
}