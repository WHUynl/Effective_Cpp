//别让异常逃离析构函数
#include <exception>
using namespace std;

//C++中不应该让析构函数吐出异常！如例所示
//数据库连接类
class DBConnection {
public:
	static DBConnection create() {}//该函数返回DBConnection对象

	void close() {} //关闭联机，失败则抛出异常
};

//管理DBConnection类,不适合的做法
class DBConnBad{
public:
	~DBConnBad();//其无法对"导致close抛出异常"的情况作出反应,但保证了析构过程中将异常捕捉到
private:
	DBConnection db;
};

DBConnBad::~DBConnBad() {
	try {
		db.close();
	}
	catch (exception& e) {
		//制作运转记录，记下对close的调用失败
	}
}

//该方法将释放资源由客户主动调用（pubic 的close()函数），同时使用析构函数作为双重保险
class DBConnGood {
public:
	void close() { db.close(); closed = true; }
	~DBConnGood();
private:
	DBConnection db;
	bool closed;
};

DBConnGood::~DBConnGood() {
		if (!closed) {
			try {
				db.close();
			}
			catch (exception& e) {
				//制作运转记录，记下对close的调用失败
			}
		}
}

/*
总结
1.析构函数绝对不要吐出异常。如果一个被析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下它们（不传播）或结束程序。
2.如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class 应该提供一个普通函数（而非在析构函数中）执行该操作

*/