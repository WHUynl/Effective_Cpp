//确定对象被使用前已先被初始化
#include<iostream>
#include<list>


using namespace std;
class Dictionary;

class ABEntry
{
public:
	ABEntry(const string& n,const list<Dictionary> d);
	ABEntry(const string& n, const list<Dictionary> d,int nn,const int cnn);
private:
	string name;
	list<Dictionary> dic;
	int num;
	//注意const和references一定需要初值，不能被赋值！
	const int constNum;
};

//这样是不对的，C++规定对象成员变量的初始化应该发生在进入构造函数本题之前！！
ABEntry::ABEntry(const string& n, const list<Dictionary> d):constNum(2)
{
	//下面两个会优先调用各自的default构造函数
	name = n;//赋值
	dic = d;//赋值

	num = 0;//赋值
	//constNum = 2;这句话一定会报错,因为这就是赋值行为

}

//正确的成员成员初值列式的初始化。且初始化顺序至于成员声明顺序相关，与成员初值列无关。
ABEntry::ABEntry(const string& n, const list<Dictionary> d,int nn,const int cnn):name(n),dic(d),num(nn),constNum(cnn)
{
}

//non-local static对象的初始化顺序
//也是单例模式的实现实现之一
//该方法优于extern的地方在于，无需考虑初始化顺序，保证一定会调用一个已经初始化的对象
//local-static 对象为函数内的static对象
class FileSystem {
public:
	int fileSize() { return 5; }
};
FileSystem tfs() {
	static FileSystem fs;
	return fs;
}

class Dictionary{
public:
	Dictionary(int n) :num(n) {}
	Dictionary() :num(0) {}
private:
	int num;
};
Dictionary& tempDir() {
	static Dictionary td;
	return td;
}


/*
int main() {

	Dictionary d(tfs().fileSize());
}
*/

/*
总结
1.为内置型对象进行手工初始化，因为C++不保证初始化它们。
2.构造函数最好使用成员初值列 ( member initialization list) ，而不要在构造函数本体内使用赋值操作 (assignment) 。初值列列出的成员变量，其排列次序应该和它们在class 中的声明次序相同。
3.为免除“跨编译单元之初始化次序”问题，请以 local static 对象替换 non-local static 对象。

*/