//ѧϰ����ģ�廯���������
#include<iostream>
using namespace std;

//������������̳�ģ����࣬�����û���ĺ���ʱ���������⡣

template <typename T>
class Base43 {
public:
	void writeA() { cout << "OnlyA" << endl; }
	virtual void wirteAB(){ cout << "A and B" << endl; }
	virtual void useBaseWriteAB() { wirteAB(); }
};

template <typename T>
class Derived43A :public Base43<T> {
public:
	void useBaseWriteA(){
		//writeA();�������ᱨ���Ҳ�����ʶ����Ϊʲô�أ����ǿ���ʹ��һ���ػ���˵��
	}
};

/*
�������ػ�������Base43������û��writeA(); ������
�Ӷ��ᵼ�´��󣬹ʱ�����Ĭ����������Υ������public
�������������Ρ�
*/
template <>
class  Base43<double> {
public:
	virtual void wirteAB() { cout << "Base A and B" << endl; }
};
/*
�����������õ�����:
*/

template <typename T>
class Derived43AB :public Base43<T> {
public:
	using Base43<T>::wirteAB;//1.���߱��������÷���λ��base class��
	void useBaseWriteAB() {
		wirteAB();
		this->wirteAB();//2.ʹ��thisָ��
		//Base43<T>::wirteAB();//��⣬�ƻ���virtual������
	}
	virtual void wirteAB() { cout << "DerivedAB A and B" << endl; }
};

int main() {
	shared_ptr<Base43<int>> b(new Derived43AB<int>);
	b->useBaseWriteAB();
}

/*
�ܽ�
1.����derived class templates ��ͨ����this->" ָ��base class templates�ڵĳ�Ա���ƣ�
�����һ������д���ġ�base class �ʸ����η�����ɡ�
*/