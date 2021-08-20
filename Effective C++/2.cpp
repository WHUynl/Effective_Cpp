//尽量以const,enum,inline 替换#define
//下述define还是存在严重问题

#include<iostream>

#define CALL_WITH_MAX(a,b) f((a)>(b)?(a):(b))

template <typename T>
void f(T a) {
	using namespace std;
	cout <<"a的值为" << a << endl;
}

//template inline 可以完美代替#define
template <typename T>
inline void CallWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}

class GamePlayer {
private:
	static const int NumTurns = 5;//class内的专属常量声明式，为保证其只有一份，故声明为staitic
	int scores[NumTurns];

	//旧编译器中由于不允许static成员在声明式中获得初值，故使用enum来进行替代。
	enum {NumTurns2 =6};
	int score2[NumTurns2];

};

//当需要取class专属常量的地址时，需要一个定义式
const int GamePlayer::NumTurns;

/*
int main() {
	using namespace std;
	int a = 5, b = 0;
	//使用template inline a的值不会有问题
	CallWithMax(++a, b);//a输出应该是6
	a=5;
	CALL_WITH_MAX(++a, ++b);//输出的a值居然是7！！因为define 将（++a整个视为了a）,所以f中相当于执行的是： cout <<"a的值为" << ++a << endl;
}
*/


/*
总结
1.对于单纯常量，最好以const对象获enums替换#define
2.对于形似函数的宏，最好改用inline函数替换#defines
*/