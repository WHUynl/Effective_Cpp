//宁以pass-by-reference-to-const替换pass-by-value
#include<iostream>
using namespace std;

class Window {
public:
	Window(string n):windowName(n){}
	string name() const;//返回窗口
	virtual void display() const;//显示窗口和内容
private:
	string windowName;
};

string Window::name() const {
	return windowName;
}

void Window::display() const{
	cout << "这是基类的display" << endl;
}

class WindowWithScrollBars :public Window {
public:
	WindowWithScrollBars(string n) :Window(n) {}
	virtual void display() const;
};

void WindowWithScrollBars::display() const {
	cout << "这是派生类的display" << endl;
}

//当参数使用传值方式时，那么会出现问题
void printNameAndDisplay(Window w) {
	cout << w.name() << endl;
	w.display();
}

//传址的优势：1.减少副本构造和销毁带来的开销 2.virtual可以使用
void printNameAndDisplayRef(const Window& w) {
	cout << w.name() << endl;
	w.display();
}

/*
int main() {
	//明显derived class却无法调用display,因为不是地址故不能调用virtual
	WindowWithScrollBars w1("derived");
	printNameAndDisplay(w1);
	//传址则可以调用virtual
	printNameAndDisplayRef(w1);
}
*/

/*
1.尽量以 pass-by-reference-to-const 替换 pass-by-value。前者通常比较高效，并可避免切割问题 ( slicing problem) 。
2.以上规则并不适用于内置类型，以及STL的迭代器和函数对象。对它们而言，pass-by-value往往比较适当。
*/