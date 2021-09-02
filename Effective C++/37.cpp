//�������¶���̳ж�����ȱʡ����ֵ
#include<iostream>
using namespace std;
/*
����һ������֪�����¶���non-virtual�����Ǵ���ģ�
���Ա�����ֻ�ÿ��Ǵ�ȱʡֵ��virtual������
�ܽ�����ɺܼ򵥣�virtual�Ƕ�̬�󶨣���ȱʡ����ֵ�Ǿ�̬��
*/

class Shape {
public:
	enum ShapeColor{Red,Green,Blue};
	//������״�ṩһ�������������Լ�����
	virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle :public Shape {
public:
	//һ���������
	virtual void draw(ShapeColor color = Green) const {
		cout << "Rectangle����ɫ" << color << endl;
	}
};

class Circle :public Shape {
public:
	//һ���������
	virtual void draw(ShapeColor color) const {
		cout << "Circle����ɫ" << color << endl;
	}
};
/*
ע�⣬ȱʡֵ�ɾ�̬�󶨾�������ִ�еĺ����ɶ�̬�󶨾���.
*/

/*
int main() {
	Shape* ps;
	Shape* pr = new Rectangle;
	Shape* pc = new Circle;
	//���������ľ�̬���;�ΪShape*
	ps = pc;//ps�Ķ�̬���ͱ�ΪCircle*
	ps = pr;//ps�Ķ�̬���ͱ�ΪRectangle*
	//��̬����ָ���ǡ�Ŀǰ��ָ��������͡������Ա��ֶ���ɱ��ֵ���Ϊ
	pr->draw();//���õ�ȴ��draw(Red)�������������Green
	pc->draw();//ָ�뷽ʽ���Բ���Ҫ������ԭ��������Ϊ�̳л����ȱʡֵ��
	Circle c;
	c.draw(Shape::Green);//��ʱ����ָ����������Ϊ�ⲻ�Ƕ�̬��
}
*/
/*
�ܽ�
1.���Բ�Ҫ���¶���һ���̳ж�����ȱʡ����ֵ����Ϊȱʡ����ֵ���Ǿ�̬�󶨣�
 ��virtual����������ΨһӦ�ø�д�Ķ��������Ƕ�̬�󶨡�
*/