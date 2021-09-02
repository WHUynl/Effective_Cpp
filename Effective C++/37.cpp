//绝不重新定义继承而来的缺省参数值
#include<iostream>
using namespace std;
/*
由上一条可以知道重新定义non-virtual函数是错误的，
所以本条款只用考虑带缺省值的virtual函数。
总结的理由很简单：virtual是动态绑定，而缺省参数值是静态绑定
*/

class Shape {
public:
	enum ShapeColor{Red,Green,Blue};
	//所有形状提供一个函数来绘制自己本身。
	virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle :public Shape {
public:
	//一个糟糕的设计
	virtual void draw(ShapeColor color = Green) const {
		cout << "Rectangle的颜色" << color << endl;
	}
};

class Circle :public Shape {
public:
	//一个糟糕的设计
	virtual void draw(ShapeColor color) const {
		cout << "Circle的颜色" << color << endl;
	}
};
/*
注意，缺省值由静态绑定决定，而执行的函数由动态绑定决定.
*/

/*
int main() {
	Shape* ps;
	Shape* pr = new Rectangle;
	Shape* pc = new Circle;
	//上述三个的静态类型均为Shape*
	ps = pc;//ps的动态类型变为Circle*
	ps = pr;//ps的动态类型变为Rectangle*
	//动态类型指的是“目前所指对象的类型”，用以表现对象可表现的行为
	pr->draw();//调用的却是draw(Red)而非我们所想的Green
	pc->draw();//指针方式可以不需要参数的原因，正是因为继承基类的缺省值。
	Circle c;
	c.draw(Shape::Green);//此时必须指明参数，因为这不是动态绑定
}
*/
/*
总结
1.绝对不要重新定义一个继承而来的缺省参数值，因为缺省参数值都是静态绑定，
 而virtual函数——你唯一应该覆写的东西——是动态绑定。
*/