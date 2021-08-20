//若不想使用编译器自动生成的函数，就该明确拒绝


//继承Uncopyable可以将连接时的问题提前移到编译器
class Uncopyable {
protected:
	Uncopyable() {} //允许derived对象构造和析构
	~Uncopyable() {}
private:
	Uncopyable(const Uncopyable&);//但组织copy
	Uncopyable& operator= (const Uncopyable&);
};

class HomeForSale :private Uncopyable {
	//class内不再声明copy构造函数或copy assign. 操作符
};

/*
总结
1.为驳回编译器自动（暗自）提供的机能，可将相应的成员函数声明为private 并且不予实现。使用像Uncopyable这样的 base class 也是一种做法。
*/
