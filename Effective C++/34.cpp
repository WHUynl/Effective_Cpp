//���ֽӿڼ̳к�ʵ�ּ̳�
#include<iostream>
using namespace std;
class Airplane {
public:
	virtual void draw() const = 0;
	virtual void fly() { cout<<"ȱʡ����Ϊȴ��һ���ã�����̳����������¶�����ܻ��������" << endl; }
	//һ�ֽ����������
	virtual void fly2() const = 0;

	int objectID() const { return 2; }
protected:
	void defaultFly() { cout<<"ʹ��һ��protected������ʵ��ȱʡ��Ϊ�����ڼ̳еĴ��麯���Ķ����е��øú����������" << endl; }

};

//���麯��Ҳ���Ա����壬��Ȼ��Ӧ��
void Airplane::draw() const {
	cout << "���ി�麯���ĵ��÷���base->Shape::draw();" << endl;
}


//1.����һ��pure virtual������Ŀ����Ϊ����derived classesֻ�̳к����ӿڡ�
//2.�������ӵģ��Ǵ�impure virtual ������Ŀ�ģ�����derived classes �̳иú����Ľӿں�ȱʡʵ�֡�
//3.����non-virtual ������Ŀ����Ϊ����derived classes �̳к����Ľӿڼ�һ��ǿ����ʵ�֡�


/*
�ܽ�
1.�ӿڼ̳к�ʵ�ּ̳в�ͬ����public�̳�֮�£�derived classes ���Ǽ̳�base class�Ľӿڡ�
2.pure virtual����ֻ����ָ���ӿڼ̳С�
3.���ӵģ��Ǵ���impure virtual ��������ָ���ӿڼ̳м�ȱʡʵ�ּ̳С�
4.non-virtual��������ָ���ӿڼ̳��Լ�ǿ����ʵ�ּ̳С�
*/