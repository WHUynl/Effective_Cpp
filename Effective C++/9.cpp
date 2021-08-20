//绝不在构造函数和析构和过程中调用virtual函数
#include<iostream>
using  namespace std;

/*
在构造和析构函数中，不可以使用virtual函数
--------------------------------------------
原因:在derived class对象的base class构造期间，对象的类型是base class而不是derived class。所以对象在derived class构造函数开始执行前不会成为一个derived class对象。

同理:一旦derived class析构函数开始执行，对象内的derived class成员变量便呈现未定义值，所以C++视它们仿佛不再存在。
*/
class Transaction {
public:
	explicit Transaction(const string& logInfo);
	void logTransaction(const string& logInfo) const {}
};

Transaction::Transaction(const string& logInfo) {
	logTransaction(logInfo);
}

class BuyTransaction :public Transaction {
public:
	BuyTransaction(int t, const string& logInfo) :test(t), Transaction(logInfo) {}
private:
	int test;
};

/*
总结
1.在构造和析构期间不要调用virtual函数，因为这类调用从不下降至derived class
（比起当前执行构造函数和析构函数的那层） 。
*/