//�����в�����������ת������Ϊ�˲���non-member����
#include<iostream>
using namespace std;
class Rational
{
public:
	//��û��ʹ��excplit,ʹint->Ratonal������int��ֵ��������ʼ�� n)
	Rational(int num = 0, int den = 1);

	int numerator() const { return n; };
	int denominator() const { return d; };
	//��class�ڵ�operator
	//const Rational operator*(const Rational& rhs) const;
private:
	int n, d;
};
/*
const Rational Rational::operator*(const Rational& rhs) const {
	Rational tmp(this->numerator() * rhs.numerator(), this->denominator() * rhs.denominator());
	return tmp;
}
*/

/*
ע��ֻ�е����������ڲ����� (parameter list)�ڣ��������������ʽ����ת���ĺϸ�����ߡ�
��ʹ��non-member������ʵ�ֽ��������⣬ע�⹹�캯��������non-explicit
*/

const Rational operator*(const Rational& lhs,const Rational& rhs)  {
	Rational tmp(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
	return tmp;
}

/*
int main() {
	Rational oneHalf(1, 2);
	Rational result = oneHalf * 2;//OK
	result = 2 * result;//ҲOK
	cout << result.numerator() << endl;

}
*/

/*
�ܽ�

�������ҪΪĳ�����������в�����������thisָ����ָ���Ǹ�������������������ת������ô������������Ǹ�non-member��
*/