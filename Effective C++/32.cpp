//确定你的public继承塑模出is-a关系
/*
每一个在Base实现的功能在每个Derived中均可以实现，
但请注意，该项可能会比较反直觉，例如下方矩形和正方形的例子
*/

#include <cassert>
class Rectangle {
public:
	virtual void setHeight(int H) { height = H; }
	virtual void setWidth(int W) { width = W; }
	virtual int heightValue() const { return height; }
	virtual int widthValue() const { return width; }
private:
	int height;
	int width;
};

/*
本段代码的作用是让矩形的宽加10，保证矩形的高度不变，否则使用断言结束程序。
然而很明显如果正方形的话则改代码会破坏掉正方形原有的法则。
*/

void makeBigger(Rectangle& r) {
	int oldHeight = r.heightValue();
	r.setWidth(r.widthValue() + 10);
	assert(r.heightValue() == oldHeight);
}

/*
总结
"public继承"意味is-a。适用于base classes身上的每一件事情 一定也适用于
derived classes 身上，因为每一个derived class对象也都是一个base class对象。

*/