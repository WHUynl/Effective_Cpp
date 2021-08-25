//尽量少做转型动作
#include<iostream>
using namespace std;
/*
旧式转型
(T)expression
T(expression)

新式转型

const_cast<T>(expression) 将对象的常量性去除
dynamic_cast<T>(expression) “安全向下转移” base->derived
reinterpret_cast<T>(expression) 意图执行低级转型，世界结果取决于编译器，故不可移植。 例如 int*->int
static_cast<T>(expression) 强迫转换，const->non-const除外

*/

//转型的需要小心的地方
class Window {
public:
	virtual void onResize() { n++; }
	int n = 0;
};

class SpecialWindow :public Window {
public:
	virtual void onResize() {
		//很遗憾你这调用的是static_cast生成的副本，故n的值并没有增加！
		static_cast<Window>(*this).onResize();
		//正确的做法是这样的,这样才是调用了本题的this指针。
		Window::onResize();
		cout << n<<endl;
	}
};

//注意慎用dynamic_cast其会大量调用strcmp

/*
int main() {
	SpecialWindow sp;
	sp.onResize();
}
*/

/*
总结
1.如果可以，尽量避免转型，特别是在注重效率的代码中避免 dynamic_casts。如果有个设计需要转型动作，试着发展无需转型的替代设计。
2.如果转型是必要的，试着将它隐藏于某个函数背后。客户随后可以调用该函数， 而不需将转型放进他们自己的代码内。
3.宁可使用C++-style（新式）转型，不要使用旧式转型。前者很容易辨识出来， 而且也比较有着分门别类的职掌。

*/