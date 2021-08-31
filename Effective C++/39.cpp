//明智而谨慎的使用private继承
#include<iostream>
using namespace std;
/*
private继承意味is-implemented-in-terms-of与复合是一致的，如何取舍呢？
尽可能使用复合，必要时才是用private继承。何时为必要呢？
当protected成员和virtual牵扯到时才为必要。
*/

//假定出现下述情况，Widget要使用Timer
class Timer {
public:
	virtual void onTick() const;//定时器函数
};

//一种普通设计，只能使用private继承，来重新定义函数
class Widget39_1 :private Timer {
private:
	virtual void onTick() const { cout << "Widget39_1的onTick"<<endl; }
};

/*
正确的设计是使用类中类的public继承来实现,优点
1.可以保证Widget的derived类不能在重新定义onTick
2.降低编译依存性
*/
class Widget39_2 {
private:
	class WidgetTimer :public Timer {
	public:
		virtual void onTick() const { cout << "WidgetTimer的onTick" << endl; }
	};
	WidgetTimer timer;
};

//private的使用原则的情形
// 
//没有数据，所以对象应该不使用任何内存
class Empty {
	/*
	一般会含有typedef，enums,static成员变量，或non-virtual函数
	*/
};

class HoldsAnInt {
private:
	int x;
	Empty e;//理论上不应该占据内存，可他占据了1。
};

class HoldsAnInt2 :private Empty {//此时就节省了内存
	int x;
};

/*
总结
1.Private 继承意味is-implemented- in-termsof（根据某物实现出）。它通常比复合( composition)的级别低。
但是当derived class 需要访问protected base class 的成员，或需要重新定义继承而来的virtual 函数时，这么设计是合理的。
2.和复合 (composition) 不同，private 继承可以造成empty base 最优化。
这对致力于“对象尺寸最小化”的程序库开发者而言，可能很重要。
*/