//Ϊ��̬��������virtual��������
#include<iostream>
using namespace std;

//һ�������
class Base {
public:
	virtual ~Base() { cout << "����Base����������" << endl; }
};

class Derived:public Base 
{
public:
	~ Derived(){ cout << "����Derived����������" << endl; }
};

//ҲҪע��һЩ���ö���������������� non-virtual�ģ����ᵼ�³�ª�Ĵ���
//����string��

class SpecialString:public string
{
public:
	~SpecialString() { cout << "��仰����Զ����ͨ��delete����ָ����д���"<<endl; }
private:

};

/*
int main() {
	Base* b = new Derived;
	delete b;//��ʱ��֤�ȵ���Derived�������������ٵ���Base����������
	string* a = new SpecialString;
	delete a;//�޷�����Derived����������
}
*/

/*
�ܽ�
1.polymorphic������̬���ʵģ�base classes Ӧ������һ�� virtual �������������
class �����κ�virtual ����������Ӧ��ӵ��һ��virtual����������

2.Classes �����Ŀ�����������Ϊ base classes ʹ�ã�����Ϊ�˾߱���̬��
( polymorphically)���Ͳ������� virtual ����������
*/
