//以独立语句将newed对象宣入智能指针
#include<iostream>
using namespace std;
class Widget {};

int priority() { return 0; }
void processWidget(shared_ptr<Widget> pw, int priority) {}

void notGood() {
//一个不规范的代码编写如下所示：
	processWidget(shared_ptr<Widget>(new Widget), priority());
/*
上述代码中,我们期望的顺序
·	执行 "new  Widget"
·	调用 shared_ptr 的构造函数
·  调用 priority()
-------------------------------
但实际的顺序缺失随机的，有可能是
·	执行 "new  Widget"
·  调用 priority()
·	调用 shared_ptr 的构造函数
那么假如调用 priority出现异常，很有可能导致new的内存泄漏（因为其指针丢失）
*/
//合适的调用
	shared_ptr<Widget> pw(new Widget);
	processWidget(pw, priority());

}
/*
总结
1.以独立语句将 newed 对象存储于（置入）智能指针内。如果不这样做，一旦异常被抛出，有可能导致难以察觉的资源泄漏。

*/