//���ƶ���ʱ������ÿһ���ɷ�
#include<iostream>
using namespace std;


/*
�������Լ��������ں����󣬱�����������������⡣
*/
void logCall(const string& function){
	//����һ��log entry
	cout << function << endl;
}

class Customer {
public:
	Customer(string n) :name(n) {}
	Customer(const Customer& rhs);
	Customer& operator=(const Customer& rhs);
private:
	string name = "test";
};

Customer::Customer(const Customer& rhs) :name(rhs.name) { logCall("Customer �Ŀ������캯��"); }

Customer& Customer::operator=(const Customer& rhs) {
	logCall("Customer �ĸ�ֵ����");
	name = rhs.name;
	return *this;
}

class PriorCustomer :public Customer {
public:
	PriorCustomer(int p, string s) :priority(p), Customer(s) {}
	PriorCustomer(const PriorCustomer& rhs);
	PriorCustomer& operator=(const PriorCustomer& rhs);
private:
	int priority = 10;
};

//ע���derived class�������캯�������������������Base�Ŀ������캯��
PriorCustomer::PriorCustomer(const PriorCustomer& rhs) :priority(rhs.priority),Customer(rhs) { logCall("PriorCustomer �Ŀ������캯��"); }

PriorCustomer& PriorCustomer::operator=(const PriorCustomer& rhs) {
	logCall("PriorCustomer �ĸ�ֵ����");
	Customer::operator=(rhs);//ͬ��ע���������������Base��copy��ֵ����
	priority = rhs.priority;
	return *this;
}

int main() {
	PriorCustomer p1(1,"p1");
	PriorCustomer p2(2,"p2");
	p1 = p2;
	PriorCustomer p3(p1);
}

/*
�ܽ�
1.Copying����Ӧ��ȷ�����ơ������ڵ����г�Ա��������������base class �ɷ֡���
2.��Ҫ������ĳ��copying����ʵ����һ��copying������Ӧ�ý���ͬ���ܷŽ������������У���������copying������ͬ���á�

*/