//区分接口继承和实现继承
#include<iostream>
using namespace std;
class Airplane {
public:
	virtual void draw() const = 0;
	virtual void fly() { cout<<"缺省的行为却不一定好，如果继承类忘记重新定义可能会出现问题" << endl; }
	//一种解决方法如下
	virtual void fly2() const = 0;

	int objectID() const { return 2; }
protected:
	void defaultFly() { cout<<"使用一个protected函数来实现缺省行为，并在继承的纯虚函数的定义中调用该函数来解决。" << endl; }

};

//纯虚函数也可以被定义，虽然不应该
void Airplane::draw() const {
	cout << "基类纯虚函数的调用方法base->Shape::draw();" << endl;
}


//1.声明一个pure virtual函数的目的是为了让derived classes只继承函数接口。
//2.声明简朴的（非纯impure virtual 函数的目的，是让derived classes 继承该函数的接口和缺省实现。
//3.声明non-virtual 函数的目的是为了令derived classes 继承函数的接口及一份强制性实现。


/*
总结
1.接口继承和实现继承不同。在public继承之下，derived classes 总是继承base class的接口。
2.pure virtual函数只具体指定接口继承。
3.简朴的（非纯）impure virtual 函数具体指定接口继承及缺省实现继承。
4.non-virtual函数具体指定接口继承以及强制性实现继承。
*/