//�����ڹ��캯���������͹����е���virtual����
#include<iostream>
using  namespace std;

/*
�ڹ�������������У�������ʹ��virtual����
--------------------------------------------
ԭ��:��derived class�����base class�����ڼ䣬�����������base class������derived class�����Զ�����derived class���캯����ʼִ��ǰ�����Ϊһ��derived class����

ͬ��:һ��derived class����������ʼִ�У������ڵ�derived class��Ա���������δ����ֵ������C++�����Ƿ·��ٴ��ڡ�
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
�ܽ�
1.�ڹ���������ڼ䲻Ҫ����virtual��������Ϊ������ôӲ��½���derived class
������ǰִ�й��캯���������������ǲ㣩 ��
*/