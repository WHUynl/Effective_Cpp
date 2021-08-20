//了解C++默默编写并调用哪些函数


//编译器会自动帮你声明一系列函数，如下例
class Empty {};//等价于
/*
class Empty{
public:
	Empty(){....}
	Empty(const Empty& rhs){...}
	-Empty(){...}
	Empty& operator=(const Empty& rhs){....}
};
*/

//但注意并非所有情况的都会自动生成，例如含有const成员或者references成员时，
class  MyClass
{
public:
	 MyClass( int ctmp,int& rtmp);

private:
	const int constTmp;
	int& reference;
};

MyClass::MyClass( int ctmp, int& rtmp) :constTmp(ctmp), reference(rtmp){
}

/*
int main() {
	int a = 10;
	int b = 12;
	MyClass my1(10, a);
	MyClass my2(12, b);
	//my1 = my2; 这句话将报错 因为上述的原因，默认copy赋值函数将不在被编译器生成

}
*/

/*
总结
1.编译器可以暗自为class创建default构造函数、copy构造函数、copy assignment 操作符，以及析构函数。
*/