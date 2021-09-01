//�˽�typename��˫������
#include<iostream>
using namespace std;
/*
template<typename T>�ȼ���template<class T>
������Ƕ�״�������ʱ����Ҫʹ��typenameָ���Ƿ�Ϊ����
��������
*/

template<class T>
static void  testTypename(){
	//T::const_iter* x; ��ᵼ������ΪT��static����const_iter��x���˷��� 
	typename T::const_iter* x;
}
/*��������*/
template<typename C>
static void f(const C& container, typename C::iterator iter) {}

/*
���������
�����Գ����� base classes list �ڵ�Ƕ�״�����������֮ǰ��
Ҳ������member initialization list����Ա��ֵ�У�����Ϊ base class ���η���
��������
*/
template<typename T>
class Base42 { class Nested { public: Nested(int x) {} }; };

template<typename T>
class Derived42 :public Base42<T>::Nested {
public:
	explicit Derived42(int x) :Base42<T>::Nested(x) {
		typename Base42<T>::Nested temp; //ֻ�д˴�ʹ��typename����������������ʹ��
	}
};

/*
�ܽ�
1.���� template ����ʱ��ǰ׺�ؼ���class��typename�ɻ�����
2.��ʹ�ùؼ���typename��ʶǶ�״����������ƣ���������base class lists�������У��� member initialization list����Ա��ֵ�У���������Ϊ base class ���η���
*/