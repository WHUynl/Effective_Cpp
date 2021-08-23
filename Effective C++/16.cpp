//成对使用new和delete时要采取相同形式

#include<iostream>
using namespace std;
typedef string Addressline[4];

void deleteFunc() {
//注意new[] 和 delete[]的成对使用，但请务必小心typdef 带来的隐患
	string* pal = new Addressline;
	//delete pal; 行为未定义!
	delete[] pal;//这才是正确的
}

/*
总结
1.如果你在new表达式中使用[], 必须在相应的delete表达式中也使用[]。 如果你在 new 表达式中不使用［］，一定不要在相应的delete表达式中使用[]。
*/