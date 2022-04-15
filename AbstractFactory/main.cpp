//3.抽象工厂模式
#include <iostream>
#include <string>
using namespace std;

//产品
class CLinux
{
public:
	virtual ~CLinux() {}
	//产品使用公共接口
	virtual void Start() = 0;
};

class CLinuxMobile : public CLinux
{
public:
	CLinuxMobile()
	{
		cout << "create linux mobile." << endl;
	}
	virtual ~CLinuxMobile() {}
	virtual void Start()
	{
		cout << "linux mobile start." << endl;
	}
};

class CLinuxPC : public CLinux
{
public:
	CLinuxPC()
	{
		cout << "create linux PC." << endl;
	}
	virtual ~CLinuxPC() {}
	virtual void Start()
	{
		cout << "linux PC start." << endl;
	}
};

class CWindows
{
public:
	virtual ~CWindows() {}
	//产品使用公共接口
	virtual void Start() = 0;
};

class CWindowsMobile : public CWindows
{
public:
	CWindowsMobile()
	{
		cout << "creat windows mobile." << endl;
	}
	virtual ~CWindowsMobile() {}
	virtual void Start()
	{
		cout << "windows mobile start." << endl;
	}
};

class CWindowsPC : public CWindows
{
public:
	CWindowsPC()
	{
		cout << "create windows PC." << endl;
	}
	virtual ~CWindowsPC() {}
	virtual void Start()
	{
		cout << "windows PC start." << endl;
	}
};

//抽象工厂
class CFactory
{
public:
	virtual ~CFactory() {}
	//产品族有多个产品组件
	virtual CLinux* CreateLinux() = 0;
	virtual CWindows* CreateWindows() = 0;
};

class CMobileFactory : public CFactory
{
public:
	CMobileFactory()
	{
		cout << "create mobile factory." << endl;
	}
	virtual ~CMobileFactory() {}
	virtual CLinux* CreateLinux()
	{
		return new CLinuxMobile;
	}
	virtual CWindows* CreateWindows()
	{
		return new CWindowsMobile;
	}
};

class CPCFactory : public CFactory
{
public:
	CPCFactory()
	{
		cout << "create PC factory." << endl;
	}
	virtual ~CPCFactory() {}
	virtual CLinux* CreateLinux()
	{
		return new CLinuxPC;
	}
	virtual CWindows* CreateWindows()
	{
		return new CWindowsPC;
	}
};

void Test(CFactory* pFactory)
{
	CLinux* pLinux = NULL;
	CWindows* pWindows = NULL;

	pLinux = pFactory->CreateLinux();
	pWindows = pFactory->CreateWindows();
	pLinux->Start();
	pWindows->Start();
	delete pWindows;
	delete pLinux;
}

int main()
{
	CFactory* pFactory = NULL;
	//手机工厂。生产手机产品族，种类有Linux和Windows
	pFactory = new CMobileFactory;
	Test(pFactory);
	delete pFactory;
	cout << endl;
	//pc工厂。生产PC产品族，种类有Linix和Windows
	pFactory = new CPCFactory;
	Test(pFactory);
	delete pFactory;

	return 0;
}

//三种工厂模式总结：
//简单工厂就是把所有产品抽象成一个基类，然后按类型在创建方法中对每个产品一一创建。优点是简单明了，缺点，这些产品必须是同一类型产品，不然抽象出的基类中就会有方法冗余。
//工厂方法就是在简单工厂的基础上中间增加一层，将创建方法提出来作为一个基类，每个子产品的创建都是单独的子类继承基类创建。
//抽象工厂就是按照不同产品划分，例如生产男衣，女衣，男裤，女裤，这种用简单工厂/工厂模式显然不合适，因为衣服和裤子的生产方法肯定不同，产品基类中会有冗余。
//所以，可以把上衣和裤子两个产品区分开来，分别抽象上衣基类和裤子基类，然后男衣/女衣继承上衣，男裤/女裤继承裤子。抽象出一个工厂基类用来提供生产这两个产品的两个方法，生产上衣和裤子。
//这样，就衍生出了两个工厂子类男士工厂和女士工厂，分别用来生产男衣/男裤，女衣/女裤。这就是抽象工厂的妙用。