//��������ת�Ͷ���
#include<iostream>
using namespace std;
/*
��ʽת��
(T)expression
T(expression)

��ʽת��

const_cast<T>(expression) ������ĳ�����ȥ��
dynamic_cast<T>(expression) ����ȫ����ת�ơ� base->derived
reinterpret_cast<T>(expression) ��ͼִ�еͼ�ת�ͣ�������ȡ���ڱ��������ʲ�����ֲ�� ���� int*->int
static_cast<T>(expression) ǿ��ת����const->non-const����

*/

//ת�͵���ҪС�ĵĵط�
class Window {
public:
	virtual void onResize() { n++; }
	int n = 0;
};

class SpecialWindow :public Window {
public:
	virtual void onResize() {
		//���ź�������õ���static_cast���ɵĸ�������n��ֵ��û�����ӣ�
		static_cast<Window>(*this).onResize();
		//��ȷ��������������,�������ǵ����˱����thisָ�롣
		Window::onResize();
		cout << n<<endl;
	}
};

//ע������dynamic_cast����������strcmp

/*
int main() {
	SpecialWindow sp;
	sp.onResize();
}
*/

/*
�ܽ�
1.������ԣ���������ת�ͣ��ر�����ע��Ч�ʵĴ����б��� dynamic_casts������и������Ҫת�Ͷ��������ŷ�չ����ת�͵������ơ�
2.���ת���Ǳ�Ҫ�ģ����Ž���������ĳ���������󡣿ͻ������Ե��øú����� �����轫ת�ͷŽ������Լ��Ĵ����ڡ�
3.����ʹ��C++-style����ʽ��ת�ͣ���Ҫʹ�þ�ʽת�͡�ǰ�ߺ����ױ�ʶ������ ����Ҳ�Ƚ����ŷ��ű����ְ�ơ�

*/