//�����쳣������������
#include <exception>
using namespace std;

//C++�в�Ӧ�������������³��쳣��������ʾ
//���ݿ�������
class DBConnection {
public:
	static DBConnection create() {}//�ú�������DBConnection����

	void close() {} //�ر�������ʧ�����׳��쳣
};

//����DBConnection��,���ʺϵ�����
class DBConnBad{
public:
	~DBConnBad();//���޷���"����close�׳��쳣"�����������Ӧ,����֤�����������н��쳣��׽��
private:
	DBConnection db;
};

DBConnBad::~DBConnBad() {
	try {
		db.close();
	}
	catch (exception& e) {
		//������ת��¼�����¶�close�ĵ���ʧ��
	}
}

//�÷������ͷ���Դ�ɿͻ��������ã�pubic ��close()��������ͬʱʹ������������Ϊ˫�ر���
class DBConnGood {
public:
	void close() { db.close(); closed = true; }
	~DBConnGood();
private:
	DBConnection db;
	bool closed;
};

DBConnGood::~DBConnGood() {
		if (!closed) {
			try {
				db.close();
			}
			catch (exception& e) {
				//������ת��¼�����¶�close�ĵ���ʧ��
			}
		}
}

/*
�ܽ�
1.�����������Բ�Ҫ�³��쳣�����һ���������������õĺ��������׳��쳣����������Ӧ�ò�׽�κ��쳣��Ȼ���������ǣ������������������
2.����ͻ���Ҫ��ĳ���������������ڼ��׳����쳣������Ӧ����ôclass Ӧ���ṩһ����ͨ���������������������У�ִ�иò���

*/