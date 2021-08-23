//必须返回对象时，别妄想返回其reference
class Rational
{
public:
	Rational(int num=0,int den=1);

private:
	int n,d;

	friend const Rational operator* (const Rational& lhs, const Rational& rhs);//正确的版本
};

Rational::Rational(int num = 0, int den = 1):n(num),d(den)
{
}

//正确版本
const Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
	return result;
}
//接下来的均为灾难的实现方式
/*
1.返回方式强行使用ref
原因：result对象分配的内存在stack区，随着 * 的函数结束，内存被自动收回，则返回的地址将十分危险
friend const Rational& operator*(const Rational& lhs, const Rational& rhs){
	Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
	return result;
}
----------------------------------------------------------------------------
2.在第一步中，使生成的result是一个指针
原因：内存泄漏 如 Rational d=a*b*c时，则本行代码调用了2次new!却没有delete
friend const Rational& operator*(const Rational& lhs, const Rational& rhs){
	Rational* result=new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	return *result;
}
----------------------------------------------------------------------------
3.使用static来将返回值保证在全局内存，
原因：(a*b)==(c*d)的值将永远为真，因为最后的值永远是static Rational 当前的值。
friend const Rational& operator*(const Rational& lhs, const Rational& rhs){
	static Rational result;
	result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	return result;
}
*/

/*
总结
绝不要返回pointer或 reference 指向一个 local stack 对象，或返回 reference 指向一个heap-allocated 对象，
或返回 pointer 或 reference 指向一个local static 对象而有可能同时需要多个这样的对象。
条款 4 已经为“在单线程环境中合理返回 reference 指向一个 local static 对象”提供了一份设计实例。
*/