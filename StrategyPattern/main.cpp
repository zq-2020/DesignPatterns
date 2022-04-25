//6.策略模式
#include <iostream>
using namespace std;

//行为基类
class Base {
public:
	virtual ~Base() {}
	virtual void Process() = 0;
};

//A行为类
class BeHaviour_A : public Base {
public:
	virtual ~BeHaviour_A() {}
	void Process() {
		cout << "A TO DO." << endl;
	}
};

//B行为类
class BeHaviour_B : public Base {
public:
	virtual ~BeHaviour_B() {}
	void Process() {
		cout << "B TO DO." << endl;
	}
};

//行为处理器
class Context {
private:
	Base* pHaviour;
public:
	Context(Base* s) { pHaviour = s; }
	void ContextProcess() {
		pHaviour->Process();
	}
};

int main() {
	Base* pA = new BeHaviour_A();
	Base* pB = new BeHaviour_B();
	Context* cA = new Context(pA);
	Context* cB = new Context(pB);
	cA->ContextProcess();  //执行A行为
	cB->ContextProcess();  //执行B行为
	delete pA; delete cA;
	delete pB; delete cB;
	return 0;
}

//可以配合工厂模式使用，cA/cB的生成可以放在工厂中