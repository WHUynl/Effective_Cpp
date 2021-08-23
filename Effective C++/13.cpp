//以对象管理资源
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
	//注意std::auto_ptr的复制以及拷贝构造函数行为会导致原来指针的对象指向null
	auto_ptr<Investment> pInv2(pInv);
	//cout << pInv->n << endl; 会报错，因为pInv已经是null

	//替代的方案，使用std::shared_ptr,引用计数型的智慧指针
	shared_ptr<Investment> pInv3(createInvestment(2));
	shared_ptr<Investment> pInv4(pInv3);
	cout << pInv3->n << endl;
	cout << pInv4->n << endl;
}
*/


/*
注意auto_ptr和shared_ptr的析构函数调用的是delete，而不会有delete[]
所以下述的代码均会是灾难性的代码
auto_ptr<string> aps(new string[10]);
shared_ptr<string> spi(new int[1024]);
*/

/*
总结
1.为防止资源泄漏，请使用 RAII对象，它们在构造函数中获得资源井在析构函数中释放资源。
2.两个常被使用的 RAII classes分别是shared_ptr和auto_ptr。前者通常是较佳选择，因为其copy行为比较直观。若选择auto_ptr，复制动作会使它（被复制物）指向null。

*/