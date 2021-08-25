//���ⷵ��handlesָ������ڲ��ɷ�
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
	Point ulhc;//���Ͻ�
	Point lrjc;//���½�
};

class Rectangle {
public:
	Rectangle(Point a, Point b) :data({a,b}),pData(make_shared<RectData>(data)){ }
	Point& upperLeft() const { return pData->ulhc; } //���ź����ǵı����ǲ�Ӧ���޸��κΣ�����Point�����ݿ��Ա��޸�
	Point& lowerRight() const { return pData->lrjc; } 
	/*���ۣ�1.��Ա�����ķ�װ�����ֻ���ڡ�������reference" �ĺ����ķ��ʼ���
	        2.���const��Ա��������һ��reference, ������ָ��������������й����������ֱ��洢�ڶ���֮�⣬��ô��������ĵ����߿����޸��Ǳ����ݡ�
	
	*/

private:
	struct RectData data;
	shared_ptr<RectData> pData;
	
};

/*
������⣺����
const Rectangle boundingBox(const GUIObject& obj);

const Point* pUpperLeft = &(boundingBox(*pgo).upperLeft());

�򱾾�ִ�����boundingBox(*pgo)������temp���󽫻ᱻ���٣���pUpperLeftָ����ڲ�����Point ���ᱻ��������������������⡣
*/

/*
int main() {
	Point coord(0, 0);
	Point coord2(100, 100);
	const Rectangle rec(coord, coord2);
	rec.upperLeft().printPos();
	rec.upperLeft().setX(50);//�����޸��˱������޸ĵ�point
	rec.upperLeft().printPos();

}
*/

/*
�ܽ�
���ⷵ��handles������ references��ָ�롢��������ָ������ڲ������������������ӷ�װ�ԣ�
����const��Ա��������Ϊ���const,������������������ơ� (dangling handles) �Ŀ����Խ�����͡�
*/