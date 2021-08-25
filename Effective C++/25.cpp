//考虑写出一个不抛异常的swap函数

/*
整理流程如下所示：
1.class或template的public提供一个swap接口
2.同一个namespace内写一个non-member的swap函数，并调用1中的swap
3.若只是class,则可特化std中的swap成员
PS:在最终调用前，先加上一句using std::swap;
下面是例子
*/
#include<iostream>

//这是swap偏特化class的swap
class Wiget {
public:
	Wiget(int n):num(n) {}
	void swap(Wiget& b){ int tmp = num; num = b.num;  b.num = tmp; }
	int num;
};

namespace std {
	template<>
	void swap<Wiget>(Wiget& a, Wiget& b) {
		a.swap(b);
		cout << "这是swap偏特化class的swap" << endl;
	}
}


//这是swap全特化class template的swap
namespace testSwap {
	template<typename T>
	class Widget {
	public:
		Widget(T n):num(n){}
		void swap(Widget<T>& b) { T tmp = num; num = b.num; b.num = tmp; }
		T num;
	};

	template<typename T>
	void swap(Widget<T>& a, Widget<T>& b) {
		a.swap(b);
		std::cout << "这是swap全特化class template的swap" << std::endl;
	}
}

template<typename T>
void doSomething(T& obj1, T& obj2) {
	using namespace std;
	swap(obj1, obj2);
}




/*
int main() {
	using namespace std;
	using namespace testSwap;
	//std::swap(obj1,obj2);这个别写其将强行调用std的swap 无论其是否特化
	Widget<int> a(1);
	Widget<int> b(2);
	doSomething<Widget<int>>(a, b);

	Wiget c(3);
	Wiget d(4);
	swap(c, d);
	cout << c.num << endl;

}
*/
/*
总结
1.当std::swap对你的类型效率不高时，提供一个swap成员函数，并确定这个函数不抛出异常。
2.如果你提供一个member swap,也该提供一个non-member swap 用来调用前者。对于classes（而非 templates) , 也请特化std::swap。
3.调用swap 时应针对std::swap使用using声明式，然后调用swap并且不带任何“命名空间资格修饰”。
4.为“用户定义类型”进行std templates全特化是好的，但千万不要尝试在std内加入某些对std而言全新的东西。

*/
