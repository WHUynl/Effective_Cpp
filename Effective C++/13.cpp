//�Զ��������Դ
#include<iostream>
using namespace std;
class Investment {
public:
	Investment(int value):n(value) {}
	int n;
};

Investment* createInvestment(int num) {
	Investment* tmp = new Investment(num);
	return tmp;
}

/*
int main() {
	auto_ptr<Investment> pInv(createInvestment(1));
	cout << pInv->n << endl;
	//ע��std::auto_ptr�ĸ����Լ��������캯����Ϊ�ᵼ��ԭ��ָ��Ķ���ָ��null
	auto_ptr<Investment> pInv2(pInv);
	//cout << pInv->n << endl; �ᱨ����ΪpInv�Ѿ���null

	//����ķ�����ʹ��std::shared_ptr,���ü����͵��ǻ�ָ��
	shared_ptr<Investment> pInv3(createInvestment(2));
	shared_ptr<Investment> pInv4(pInv3);
	cout << pInv3->n << endl;
	cout << pInv4->n << endl;
}
*/


/*
ע��auto_ptr��shared_ptr�������������õ���delete����������delete[]
���������Ĵ�������������ԵĴ���
auto_ptr<string> aps(new string[10]);
shared_ptr<string> spi(new int[1024]);
*/

/*
�ܽ�
1.Ϊ��ֹ��Դй©����ʹ�� RAII���������ڹ��캯���л����Դ���������������ͷ���Դ��
2.��������ʹ�õ� RAII classes�ֱ���shared_ptr��auto_ptr��ǰ��ͨ���ǽϼ�ѡ����Ϊ��copy��Ϊ�Ƚ�ֱ�ۡ���ѡ��auto_ptr�����ƶ�����ʹ�����������ָ��null��

*/