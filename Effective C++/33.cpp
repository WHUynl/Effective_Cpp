//�������ڼ̳ж���������
#include<iostream>
using namespace std;

namespace space33{
	class Base33 {
	public:
		virtual void mf1() = 0;
		virtual void mf1(int) { cout << "Base33��mf1(int)" << endl; }
		virtual void mf2() { cout << "Base33��mf2()" << endl; }
		void mf3() { cout << "Base33��mf3()" << endl; }
		void mf3(double){ cout << "Base33��mf3(double)" << endl; }
	private:
		int x;
	};

	/*
	mf4�����������mf2��˳��
	1.�Ȳ���local������Ҳ����mf4���ǵ������򣩣����Ƕ�û�ҵ��κζ�����Ϊmf2��
	2.��������Χ������Ҳ����class Derived���ǵ�������
	3.������Χ�ƶ�������Ϊbase class�����Ƕ��������ҵ�һ����Ϊmf2�Ķ����ˣ�����ֹͣ���ҡ�
	4.���Base�ڻ���û��mf2, ���Ҷ����������ȥ���������ں�Base���Ǹ�namespace(s)��������space33)
	5.�����global ��������ȥ
	*/
	class Derived33:public Base33 {
	public:
		virtual void mf1(){ cout << "Derived33��mf1()" << endl; }
		void mf3(){ cout << "Derived33��mf3()" << endl; }
		void mf4() { mf2(); }
	};
}


/*
������� ��Derived ��ʹ��using
class Derived{
	using Base33::mf1;
	using Base33::mf3;
};
*/
/*
int main() {
	using namespace space33;
	Derived33 d;
	d.mf4();
	cout << "----------------------------------------------" << endl;
	int x = 0;
	d.mf1();//����Derived33::mf1();
	//d.mf1(x); ������ΪDerived33::mf1����������������Base33::mf1
	d.mf2();//Base33::mf2
	d.mf3();//����Derived33::mf3();
	//d.mf3(x);����ԭ��ͬ��

	cout << "----------------------------------------------" << endl;
	//��Ȼbaseָ���ǲ�����Ӱ���
	Base33* b = new Derived33;
	b->mf1(44);

}
*/

/*
�ܽ�
1.derived classes�ڵ����ƻ�����base classes �ڵ����ơ���public �̳��´���û����ϣ����ˡ�
2.Ϊ���ñ����ڵ������ټ����գ���ʹ��using����ʽ��inlineת��������forwarding functions ) ��
*/
