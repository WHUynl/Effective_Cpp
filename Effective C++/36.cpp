//�������¶���̳ж�����non-virtual����
#include<iostream>
using namespace std;
class B {
public:
	void mf() { cout << "Base��mf()" << endl; };
};

class D :public B {
public:
	void mf() { cout << "Derived��mf()" << endl; };
};

/*
Ϊʲô�������¶���̳ж�����non-virtual������
ԭ��
��'D is a B'�ǳ����ģ���
1.������B�����ÿһ���£�Ҳ������D������Ϊÿ��D������һ�� B ����
2.B��derived classes һ����̳�mf�Ľӿں�ʵ�֣���Ϊmf��B��һ��non-virtual������

ì��֮����
���D���б�Ҫʵ�ֳ���B��ͬ��mf ���������ÿһ��B���󡪡����ܶ�ô�ػ�һ����ı���ʹ��B���ṩ��mfʵ���룬
��ô��ÿ�� D ����һ�� B" �Ͳ�Ϊ�档
*/

/*
int main() {
	D d;
	B* pb = &d;
	D* pd = &d;
	//���Ǿ�̬�󶨵��������
	pb->mf();//����Base��
	pd->mf();//����Derived��
}
*/

/*
�ܽ᣺
���Բ�Ҫ���¶���̳ж�����non-virtual ������
*/