//绝不重新定义继承而来的non-virtual函数
#include<iostream>
using namespace std;
class B {
public:
	void mf() { cout << "Base的mf()" << endl; };
};

class D :public B {
public:
	void mf() { cout << "Derived的mf()" << endl; };
};

/*
为什么绝不重新定义继承而来的non-virtual函数？
原因：
若'D is a B'是成立的，则：
1.适用于B对象的每一件事，也适用于D对象，因为每个D对象都是一个 B 对象；
2.B的derived classes 一定会继承mf的接口和实现，因为mf是B的一个non-virtual函数。

矛盾之处：
如果D真有必要实现出与B不同的mf ，并且如果每一个B对象——不管多么特化一—真的必须使用B所提供的mf实现码，
那么“每个 D 都是一个 B" 就不为真。
*/

/*
int main() {
	D d;
	B* pb = &d;
	D* pd = &d;
	//这是静态绑定的正常结果
	pb->mf();//调用Base的
	pd->mf();//调用Derived的
}
*/

/*
总结：
绝对不要重新定义继承而来的non-virtual 函数。
*/