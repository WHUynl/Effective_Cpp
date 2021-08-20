//ȷ������ʹ��ǰ���ȱ���ʼ��
#include<iostream>
#include<list>


using namespace std;
class Dictionary;

class ABEntry
{
public:
	ABEntry(const string& n,const list<Dictionary> d);
	ABEntry(const string& n, const list<Dictionary> d,int nn,const int cnn);
private:
	string name;
	list<Dictionary> dic;
	int num;
	//ע��const��referencesһ����Ҫ��ֵ�����ܱ���ֵ��
	const int constNum;
};

//�����ǲ��Եģ�C++�涨�����Ա�����ĳ�ʼ��Ӧ�÷����ڽ��빹�캯������֮ǰ����
ABEntry::ABEntry(const string& n, const list<Dictionary> d):constNum(2)
{
	//�������������ȵ��ø��Ե�default���캯��
	name = n;//��ֵ
	dic = d;//��ֵ

	num = 0;//��ֵ
	//constNum = 2;��仰һ���ᱨ��,��Ϊ����Ǹ�ֵ��Ϊ

}

//��ȷ�ĳ�Ա��Ա��ֵ��ʽ�ĳ�ʼ�����ҳ�ʼ��˳�����ڳ�Ա����˳����أ����Ա��ֵ���޹ء�
ABEntry::ABEntry(const string& n, const list<Dictionary> d,int nn,const int cnn):name(n),dic(d),num(nn),constNum(cnn)
{
}

//non-local static����ĳ�ʼ��˳��
//Ҳ�ǵ���ģʽ��ʵ��ʵ��֮һ
//�÷�������extern�ĵط����ڣ����迼�ǳ�ʼ��˳�򣬱�֤һ�������һ���Ѿ���ʼ���Ķ���
//local-static ����Ϊ�����ڵ�static����
class FileSystem {
public:
	int fileSize() { return 5; }
};
FileSystem tfs() {
	static FileSystem fs;
	return fs;
}

class Dictionary{
public:
	Dictionary(int n) :num(n) {}
	Dictionary() :num(0) {}
private:
	int num;
};
Dictionary& tempDir() {
	static Dictionary td;
	return td;
}


/*
int main() {

	Dictionary d(tfs().fileSize());
}
*/

/*
�ܽ�
1.Ϊ�����Ͷ�������ֹ���ʼ������ΪC++����֤��ʼ�����ǡ�
2.���캯�����ʹ�ó�Ա��ֵ�� ( member initialization list) ������Ҫ�ڹ��캯��������ʹ�ø�ֵ���� (assignment) ����ֵ���г��ĳ�Ա�����������д���Ӧ�ú�������class �е�����������ͬ��
3.Ϊ���������뵥Ԫ֮��ʼ���������⣬���� local static �����滻 non-local static ����

*/