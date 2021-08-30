//避免遮掩继承而来的名称
#include<iostream>
using namespace std;

namespace space33{
	class Base33 {
	public:
		virtual void mf1() = 0;
		virtual void mf1(int) { cout << "Base33的mf1(int)" << endl; }
		virtual void mf2() { cout << "Base33的mf2()" << endl; }
		void mf3() { cout << "Base33的mf3()" << endl; }
		void mf3(double){ cout << "Base33的mf3(double)" << endl; }
	private:
		int x;
	};

	/*
	mf4（）里面查找mf2的顺序：
	1.先查找local作用域（也就是mf4覆盖的作用域），在那儿没找到任何东西名为mf2。
	2.查找其外围作用域，也就是class Derived覆盖的作用域。
	3.再往外围移动，本例为base class。在那儿编译器找到一个名为mf2的东西了，于是停止查找。
	4.如果Base内还是没有mf2, 查找动作便继续下去，首先找内含Base的那个namespace(s)的作用域（space33)
	5.最后往global 作用域找去
	*/
	class Derived33:public Base33 {
	public:
		virtual void mf1(){ cout << "Derived33的mf1()" << endl; }
		void mf3(){ cout << "Derived33的mf3()" << endl; }
		void mf4() { mf2(); }
	};
}


/*
解决方法 在Derived 中使用using
class Derived{
	using Base33::mf1;
	using Base33::mf3;
};
*/
/*
int main() {
	using namespace space33;
	Derived33 d;
	d.mf4();
	cout << "----------------------------------------------" << endl;
	int x = 0;
	d.mf1();//调用Derived33::mf1();
	//d.mf1(x); 错误，因为Derived33::mf1函数名会遮掩所有Base33::mf1
	d.mf2();//Base33::mf2
	d.mf3();//调用Derived33::mf3();
	//d.mf3(x);错误原因同上

	cout << "----------------------------------------------" << endl;
	//当然base指针是不会受影响的
	Base33* b = new Derived33;
	b->mf1(44);

}
*/

/*
总结
1.derived classes内的名称会遮掩base classes 内的名称。在public 继承下从来没有人希望如此。
2.为了让被遮掩的名称再见天日，可使用using声明式或inline转交函数（forwarding functions ) 。
*/
