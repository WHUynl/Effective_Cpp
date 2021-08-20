//������ʹ��const
#include<vector>
#include<iostream>
using namespace std;

char greeting[] = "Hello";
char* p = greeting;
const char* p2 = greeting;//����ָ�룬*p2�ǳ������������޸�ָ�������
char* const p3 = greeting;//ָ�볣����p3�ǳ������������޸�ָ��ָ��Ķ���
const char* const p4= greeting;//���Ƚ��ĳ���

//STL�еĵ���ָ����΢��һ�㷴ֱ��
void constStudy() {
	vector<int> vec(10, 1);
	const vector<int>::iterator iter = vec.begin();
	*iter = 10;
//  ++iter; �ô���ᱨ����Ϊ������iter ����Ϊ T* const iter;

	vector<int>::const_iterator iter2 = vec.begin();
//  *iter = 5;�ô���ᱨ����Ϊ������iter ����Ϊ T const *iter;
	++iter2;
}

//const ͬʱҲ������Ϊ��������ֵ��ʹ����Ϊ��ֵ�����Ա�������
class Rational {
public:
	Rational(int n) :num(n) {}
	int getNum() const { return num; }//��ע�� �˴���const���˱�֤���޸ĳ�Ա����num�⣬Ҳ��֤�˸ú������Ա�const Rational ������á���Ҳ��һ������
	int getNum() { return num+1; }//��Rational�������

	//����ʹ��const���� non-const�����Ĵ��룬�����Բ��ܷ�����
	const char& operator[](std::size_t pos) const{
	//һ�Ѳ������ظ��Դ���
		return text[pos];
	}

	char& operator[](std::size_t pos) {
	//const_cast ȥ���˷���ֵ��const,��֤�˷���ֵΪchar&;static_cast ���const ʹthis���Ե�������const������ܵ��õ�����[]
		return const_cast<char&>(static_cast<const Rational&>(*this)[pos]);
	}

private:
	int num = 0;
	char* text;
};

//const ����֤������֣�a*b��= c ���������Ѵ���
const Rational operator* (const Rational& lhs, Rational& rhs) {
	int value = lhs.getNum() * rhs.getNum(); //�ֱ����������getNum;
	Rational tmp(value);
	cout << value << endl;
	return tmp;

}

/*
int main() {
	Rational a = Rational(5);
	Rational b = Rational(5);
	Rational c = a * b;
}
*/

/*
�ܽ�
1.��ĳЩ��������Ϊconst�ɰ������������������÷��� const �ɱ�ʩ�����κ��������ڵĶ��󡢺��������������������͡���Ա�������塣
2.������ǿ��ʵʩbitwise constness �������д����ʱӦ��ʹ�á������ϵĳ����ԡ� (conceptual constness) ��
3.�� const �� non-const ��Ա��������ʵ�ʵȼ۵�ʵ��ʱ����non-const �汾���� const �汾�ɱ�������ظ���
*/