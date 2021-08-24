//若所有参数皆需类型转换，请为此采用non-member函数
#include<iostream>
using namespace std;
class Rational
{
public:
	//并没有使用excplit,使int->Ratonal成立（int的值会用来初始化 n)
	Rational(int num = 0, int den = 1);

	int numerator() const { return n; };
	int denominator() const { return d; };
	//在class内的operator
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
注意只有当参数被列于参数列 (parameter list)内，这个参数才是隐式类型转换的合格参与者。
故使用non-member函数来实现将会解决问题，注意构造函数依旧是non-explicit
*/

const Rational operator*(const Rational& lhs,const Rational& rhs)  {
	Rational tmp(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
	return tmp;
}

/*
int main() {
	Rational oneHalf(1, 2);
	Rational result = oneHalf * 2;//OK
	result = 2 * result;//也OK
	cout << result.numerator() << endl;

}
*/

/*
总结

如果你需要为某个函数的所有参数（包括被this指针所指的那个隐喻参数）进行类型转换，那么这个函数必须是个non-member。
*/