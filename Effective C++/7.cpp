//为多态基类声明virtual析构函数
#include<iostream>
using namespace std;

//一般情况下
class Base {
public:
	virtual ~Base() { cout << "这是Base的析构函数" << endl; }
};

class Derived:public Base 
{
public:
	~ Derived(){ cout << "这是Derived的析构函数" << endl; }
};

//也要注意一些内置对象本身的析构函数是 non-virtual的，将会导致丑陋的代码
//例如string类

class SpecialString:public string
{
public:
	~SpecialString() { cout << "这句话将永远不能通过delete基类指针进行代用"<<endl; }
private:

};

/*
int main() {
	Base* b = new Derived;
	delete b;//此时保证先调用Derived的析构函数，再调用Base的析构函数
	string* a = new SpecialString;
	delete a;//无法调用Derived的析构函数
}
*/

/*
总结
1.polymorphic（带多态性质的）base classes 应该声明一个 virtual 析构函数。如果
class 带有任何virtual 函数，它就应该拥有一个virtual析构函数。

2.Classes 的设计目的如果不是作为 base classes 使用，或不是为了具备多态性
( polymorphically)，就不该声明 virtual 析构函数。
*/
