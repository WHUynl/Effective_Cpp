//需要类型转换时请为模板定义非成员函数

/*
条款24 已经说明了non-member函数实施隐式类型转换。
*/

template<typename T>
class Rational46 {
public:
	Rational46(const T& n = 0, const T& d = 1) :numerator(n), denominator(d) {}
	const T num() const{ return numerator; }
	const T den() const { return denominator; }


private:
	T numerator;
	T denominator;
};

template<typename T>
const Rational46<T> operator* (const Rational46<T>& lhs, const Rational46<T>& rhs) {
	Rational46<T> result(lhs.num(), rhs.den());
	return result;
}

/*
详细的正确内容，以及一些思考和反思，
见Rational46.hpp
*/

/*
int main() {
	Rational46<int> oneHalf(1, 2);//没问题
	//Rational46<int> answer = oneHalf * 2; 出大问题了，2是无法初始化模板的。因为template实参推导过程中从不将隐式类型转换函数纳入考虑。
}
*/

/*
总结
当我们编写一个 class template, 而它所提供之 “与此template 相关的＂
函数支持“所有参数之隐式类型转换”时，
请将那些函数定义为 “ class template 内部的（inline） friend 函数”。
*/