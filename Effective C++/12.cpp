//复制对象时勿忘其每一个成分
#include<iostream>
using namespace std;


/*
当我们自己声明考内函数后，编译器会忽视许多的问题。
*/
void logCall(const string& function){
	//制造一个log entry
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

Customer::Customer(const Customer& rhs) :name(rhs.name) { logCall("Customer 的拷贝构造函数"); }

Customer& Customer::operator=(const Customer& rhs) {
	logCall("Customer 的赋值函数");
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

//注意的derived class拷贝构造函数必须主动调用其基类Base的拷贝构造函数
PriorCustomer::PriorCustomer(const PriorCustomer& rhs) :priority(rhs.priority),Customer(rhs) { logCall("PriorCustomer 的拷贝构造函数"); }

PriorCustomer& PriorCustomer::operator=(const PriorCustomer& rhs) {
	logCall("PriorCustomer 的赋值函数");
	Customer::operator=(rhs);//同理，注意必须先主动调用Base的copy赋值函数
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
总结
1.Copying函数应该确保复制“对象内的所有成员变量”及“所有base class 成分“。
2.不要尝试以某个copying函数实现另一个copying函数。应该将共同机能放进第三个函数中，并由两个copying函数共同调用。

*/