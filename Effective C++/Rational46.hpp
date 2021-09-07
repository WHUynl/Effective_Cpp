/*
template的声明与定义均应该放置在头文件中，并将该文件命名为hpp
本例中关于友元函数的两个问题的思考：
1.为何友元上方函数不添加template<typename>
2.为何友元函数必须在类内定义


1.本例中使用友元函数的理由就是为了，在类模板具现化的时候直接，推断出
友元函数的参数T的类型，从而当后面接一个常数 2 的时候，则可以直接将其进行
隐式转换，即 2 -> RationReal<int>,如果添加template<typename>，则友元函数
将不再进行自动类型推断。

2.因为友元函数不能添加template<typename>，从而导致类外所谓的友元函数的“定义”
是无法与类内的友元函数匹配上的，故只能将定义写在类内，将友元函数变成inline。
*/
template<typename T>
class RationalReal
{
public:
	RationalReal(const T num = 0, const T den = 1):n(num),d(den) {}
	const T num() const { return n; }
	const T den() const { return d; }
private:
	T n;
	T d;

	friend const RationalReal operator* (const RationalReal& lhs, const RationalReal& rhs) {
		return doMultiply(lhs, rhs);
	}
};

template<typename T>
const RationalReal<T> doMultiply(const RationalReal<T>& lhs, const RationalReal<T>& rhs) {
	return RationalReal<T>(lhs.num() * rhs.num(), rhs.den() * lhs.den());
}


