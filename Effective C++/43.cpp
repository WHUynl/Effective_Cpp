//学习处理模板化基类的名称
#include<iostream>
using namespace std;

//本问题是子类继承模板基类，并调用基类的函数时引发的问题。

template <typename T>
class Base43 {
public:
	void writeA() { cout << "OnlyA" << endl; }
	virtual void wirteAB(){ cout << "A and B" << endl; }
	virtual void useBaseWriteAB() { wirteAB(); }
};

template <typename T>
class Derived43A :public Base43<T> {
public:
	void useBaseWriteA(){
		//writeA();编译器会报错找不到标识符，为什么呢？我们可以使用一个特化来说明
	}
};

/*
如下述特化例，则Base43根本就没有writeA(); 方法，
从而会导致错误，故编译器默认上述方法违法，将public
方法进行了屏蔽。
*/
template <>
class  Base43<double> {
public:
	virtual void wirteAB() { cout << "Base A and B" << endl; }
};
/*
解决方法，最好的两种:
*/

template <typename T>
class Derived43AB :public Base43<T> {
public:
	using Base43<T>::wirteAB;//1.告诉编译器，该方法位于base class内
	void useBaseWriteAB() {
		wirteAB();
		this->wirteAB();//2.使用this指针
		//Base43<T>::wirteAB();//糟糕，破坏了virtual的特性
	}
	virtual void wirteAB() { cout << "DerivedAB A and B" << endl; }
};

int main() {
	shared_ptr<Base43<int>> b(new Derived43AB<int>);
	b->useBaseWriteAB();
}

/*
总结
1.可在derived class templates 内通过“this->" 指涉base class templates内的成员名称，
或藉由一个明白写出的“base class 资格修饰符”完成。
*/