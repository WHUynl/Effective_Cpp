//����д��һ�������쳣��swap����

/*
��������������ʾ��
1.class��template��public�ṩһ��swap�ӿ�
2.ͬһ��namespace��дһ��non-member��swap������������1�е�swap
3.��ֻ��class,����ػ�std�е�swap��Ա
PS:�����յ���ǰ���ȼ���һ��using std::swap;
����������
*/
#include<iostream>

//����swapƫ�ػ�class��swap
class Wiget {
public:
	Wiget(int n):num(n) {}
	void swap(Wiget& b){ int tmp = num; num = b.num;  b.num = tmp; }
	int num;
};

namespace std {
	template<>
	void swap<Wiget>(Wiget& a, Wiget& b) {
		a.swap(b);
		cout << "����swapƫ�ػ�class��swap" << endl;
	}
}


//����swapȫ�ػ�class template��swap
namespace testSwap {
	template<typename T>
	class Widget {
	public:
		Widget(T n):num(n){}
		void swap(Widget<T>& b) { T tmp = num; num = b.num; b.num = tmp; }
		T num;
	};

	template<typename T>
	void swap(Widget<T>& a, Widget<T>& b) {
		a.swap(b);
		std::cout << "����swapȫ�ػ�class template��swap" << std::endl;
	}
}

template<typename T>
void doSomething(T& obj1, T& obj2) {
	using namespace std;
	swap(obj1, obj2);
}




/*
int main() {
	using namespace std;
	using namespace testSwap;
	//std::swap(obj1,obj2);�����д�佫ǿ�е���std��swap �������Ƿ��ػ�
	Widget<int> a(1);
	Widget<int> b(2);
	doSomething<Widget<int>>(a, b);

	Wiget c(3);
	Wiget d(4);
	swap(c, d);
	cout << c.num << endl;

}
*/
/*
�ܽ�
1.��std::swap���������Ч�ʲ���ʱ���ṩһ��swap��Ա��������ȷ������������׳��쳣��
2.������ṩһ��member swap,Ҳ���ṩһ��non-member swap ��������ǰ�ߡ�����classes������ templates) , Ҳ���ػ�std::swap��
3.����swap ʱӦ���std::swapʹ��using����ʽ��Ȼ�����swap���Ҳ����κΡ������ռ��ʸ����Ρ���
4.Ϊ���û��������͡�����std templatesȫ�ػ��Ǻõģ���ǧ��Ҫ������std�ڼ���ĳЩ��std����ȫ�µĶ�����

*/
