//了解typename的双重意义
#include<iostream>
using namespace std;
/*
template<typename T>等价于template<class T>
但遇到嵌套从属名称时则需要使用typename指明是否为类型
例子如下
*/

template<class T>
static void  testTypename(){
	//T::const_iter* x; 这会导致歧义为T的static变量const_iter与x做乘法。 
	typename T::const_iter* x;
}
/*更多例子*/
template<typename C>
static void f(const C& container, typename C::iterator iter) {}

/*
例外情况：
不可以出现在 base classes list 内的嵌套从属类型名称之前，
也不可在member initialization list（成员初值列）中作为 base class 修饰符。
例子如下
*/
template<typename T>
class Base42 { class Nested { public: Nested(int x) {} }; };

template<typename T>
class Derived42 :public Base42<T>::Nested {
public:
	explicit Derived42(int x) :Base42<T>::Nested(x) {
		typename Base42<T>::Nested temp; //只有此处使用typename，上面两处均不能使用
	}
};

/*
总结
1.声明 template 参数时，前缀关键字class和typename可互换。
2.请使用关键字typename标识嵌套从属类型名称；但不得在base class lists（基类列）或 member initialization list（成员初值列）内以它作为 base class 修饰符。
*/