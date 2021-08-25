//将文件间的编译依存关系降至最低

/*
使用interface class的一个方法：使用抽象基类，则客户需要使用Person的pointers或者references
因为不可能针对“内含pure virtual函数”的Person classes具现出实体。
整体见 31Person 和31RealPerson
*/
#include"31Person.h"

/*
使用该方法要注意的是
1.接口类应是对所有成员函数变为纯虚函数，并声明一个返回指针的static工厂函数用来创建对象
2.因为创建的对象是Person内声明的，且又需要实现类，故其必包含两者的头文件
3.客户使用时必定要用pointer的形式

好处：减少依赖性
从此对RealPerson进行修改时，只需要重新编译该类所在文件即可，外界不会感知
*/


int main() {
	string name = "ynl";
	shared_ptr<Person> pp = Person::createPerson(name);
	cout << pp->name() << endl;
}

/*
总结
1.支持“编译依存性最小化”的一般构想是：相依于声明式，不要相依于定义式。基于此构想的两个手段是 Handle classes 和 Interface classes。
2.程序库头文件应该以“ 完全且仅有声明式” ( full and declaration-only forms) 的形式存在。这种做法不论是否涉及templates都适用
*/
