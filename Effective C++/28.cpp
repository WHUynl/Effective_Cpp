//避免返回handles指向对象内部成分
#include<iostream>
using namespace std;

class Point {
public:
	Point(int x, int y) :xPos(x), yPos(y) {}
	void setX(int newVal) { xPos = newVal; }
	void setY(int newVal) { yPos = newVal; }
	void printPos() {
		cout << xPos <<" " << yPos << endl;
	}
private:
	int xPos, yPos;
};

struct RectData
{
	Point ulhc;//左上角
	Point lrjc;//右下角
};

class Rectangle {
public:
	Rectangle(Point a, Point b) :data({a,b}),pData(make_shared<RectData>(data)){ }
	Point& upperLeft() const { return pData->ulhc; } //很遗憾我们的本质是不应该修改任何，但是Point的数据可以被修改
	Point& lowerRight() const { return pData->lrjc; } 
	/*结论：1.成员变量的封装性最多只等于“返回其reference" 的函数的访问级别。
	        2.如果const成员函数传出一个reference, 后者所指数据与对象自身有关联，而它又被存储于对象之外，那么这个函数的调用者可以修改那笔数据。
	
	*/

private:
	struct RectData data;
	shared_ptr<RectData> pData;
	
};

/*
虚吊问题：例如
const Rectangle boundingBox(const GUIObject& obj);

const Point* pUpperLeft = &(boundingBox(*pgo).upperLeft());

则本句执行完后，boundingBox(*pgo)产生的temp对象将会被销毁，则pUpperLeft指向的内部对象Point 将会被析构，进而产生虚吊问题。
*/

/*
int main() {
	Point coord(0, 0);
	Point coord2(100, 100);
	const Rectangle rec(coord, coord2);
	rec.upperLeft().printPos();
	rec.upperLeft().setX(50);//我们修改了本不可修改的point
	rec.upperLeft().printPos();

}
*/

/*
总结
避免返回handles（包括 references、指针、迭代器）指向对象内部。遵守这个条款可增加封装性，
帮助const成员函数的行为像个const,并将发生“虚吊号码牌” (dangling handles) 的可能性降至最低。
*/