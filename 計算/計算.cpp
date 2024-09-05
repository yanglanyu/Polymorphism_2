#include<iostream>
#include<string>
using namespace std;

class Calculator
{
public:
	int Num1;
	int Num2;

	int getResult(string oper)
	{
		if (oper == "+") {
			return Num1 + Num2;
		}
		else if (oper == "-") {
			return Num1 - Num2;
		}
		else if (oper == "*") {
			return Num1 * Num2;
		}
	}
};

void test_1()
{
	Calculator c;
	c.Num1 = 10;
	c.Num2 = 5;

	cout << c.Num1 << "+" << c.Num2 << "=" << c.getResult("+") << endl;
	cout << c.Num1 << "-" << c.Num2 << "=" << c.getResult("-") << endl;
	cout << c.Num1 << "*" << c.Num2 << "=" << c.getResult("*") << endl;
}

//多态实现抽象计算器类
//多态优点：代码组织结构清晰可读性强利于前期和后期的扩展以及维护

class AbstractCalculator
{
public:
	int Num1;
	int Num2;

	virtual int getResult()
	{
		return 0;
	}
};
class AddCalculator :public AbstractCalculator
{
	int getResult()
	{
		return Num1 + Num2;
	}
};
class SubCalculator :public AbstractCalculator
{
	int getResult()
	{
		return Num1 - Num2;
	}
};
class MulCalculator :public AbstractCalculator
{
	int getResult()
	{
		return Num1 * Num2;
	}
};
void test_2()
{
	//new加类名创建出一个类的指针
	//父类指针或引用指向子类对象

	//加算
	AbstractCalculator* abc = new AddCalculator;
	abc->Num1 = 10;
	abc->Num2 = 5;
	cout << abc->Num1 << "+" << abc->Num2 << "=" << abc->getResult() << endl;
	delete abc;		// delete只是释放内存，这个指针abc还是指向原来指向的地址的，下面可以接着用这个指针（下面换地址了）

	//減算
	abc = new SubCalculator;
	abc->Num1 = 10;
	abc->Num2 = 5;
	cout << abc->Num1 << "-" << abc->Num2 << "=" << abc->getResult() << endl;
	delete abc;

	//乗算
	abc = new MulCalculator;
	abc->Num1 = 10;
	abc->Num2 = 5;
	cout << abc->Num1 << "*" << abc->Num2 << "=" << abc->getResult() << endl;
	delete abc;
}

int main()
{
	test_1();
	printf("------------\n");
	test_2();

	return 0;
}