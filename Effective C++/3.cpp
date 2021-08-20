//尽可能使用const
#include<vector>
#include<iostream>
using namespace std;

char greeting[] = "Hello";
char* p = greeting;
const char* p2 = greeting;//常量指针，*p2是常量，即不能修改指针的内容
char* const p3 = greeting;//指针常量，p3是常量，即不能修改指针指向的对象
const char* const p4= greeting;//最稳健的常量

//STL中的迭代指针稍微有一点反直觉
void constStudy() {
	vector<int> vec(10, 1);
	const vector<int>::iterator iter = vec.begin();
	*iter = 10;
//  ++iter; 该代码会报错，因为本例中iter 可视为 T* const iter;

	vector<int>::const_iterator iter2 = vec.begin();
//  *iter = 5;该代码会报错，因为本例中iter 可视为 T const *iter;
	++iter2;
}

//const 同时也可以作为函数返回值，使其作为右值，用以保护程序
class Rational {
public:
	Rational(int n) :num(n) {}
	int getNum() const { return num; }//请注意 此处的const除了保证不修改成员变量num外，也保证了该函数可以被const Rational 对象调用。这也是一种重载
	int getNum() { return num+1; }//给Rational对象调用

	//可以使用const来简化 non-const函数的代码，但绝对不能反过来
	const char& operator[](std::size_t pos) const{
	//一堆操作，重复性代码
		return text[pos];
	}

	char& operator[](std::size_t pos) {
	//const_cast 去掉了返回值的const,保证了返回值为char&;static_cast 添加const 使this可以调用属于const对象才能调用的重载[]
		return const_cast<char&>(static_cast<const Rational&>(*this)[pos]);
	}

private:
	int num = 0;
	char* text;
};

//const 将保证不会出现（a*b）= c 这样的灾难代码
const Rational operator* (const Rational& lhs, Rational& rhs) {
	int value = lhs.getNum() * rhs.getNum(); //分别调用了两个getNum;
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
总结
1.将某些东西声明为const可帮助编译器侦测出错误用法。 const 可被施加于任何作用域内的对象、函数参数、函数返回类型、成员函数本体。
2.编译器强制实施bitwise constness ，但你编写程序时应该使用“概念上的常量性” (conceptual constness) 。
3.当 const 和 non-const 成员函数有着实质等价的实现时，令non-const 版本调用 const 版本可避免代码重复。
*/