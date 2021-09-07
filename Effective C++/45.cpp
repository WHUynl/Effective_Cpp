//条款45 运用成员函数模板接收所有兼容类型
#include<iostream>
#include<string>
using namespace std;

class Top{};
class Middle:public Top{};

template<typename T>
class SmartPtr45 {
public:
	explicit SmartPtr45(T* realPtr) :dataPtr(realPtr) {}
private:
	T* dataPtr;
};

template<typename T>
class SmartPtr245 {
public:
	explicit SmartPtr245(T* realPtr) :dataPtr(realPtr) {}
	/*
	泛华copy构造函数,该版本还是有个问题
	我们不该产生 Top给Middle生成的情况出现。
	*/
	template<typename U>
	SmartPtr245(const SmartPtr245<U>& other) {}
	T* dataPtr;
};

template<typename T>
class SmartPtr345 {
public:
	explicit SmartPtr345(T* realPtr) :dataPtr(realPtr) {}
	/*
	泛华copy构造函数,该版本还是有个问题
	*/
	template<typename U>
	//使用成员初值列表的方法，来进行显示的使用U*指针为T*指针赋值，以及get()方法，让编译器来解决问题。
	SmartPtr345(const SmartPtr345<U>& other) : dataPtr(other.get()) {}
	T* get() const{ return dataPtr; }
private:
	T* dataPtr;
};

/*
但请注意，就算使用了成员函数模板来构造默认函数，
我们也需要自己手动定义，否则编译器还是会自动生成。
*/

template<typename T>
class Shared_Ptr {

	//copy构造函数
	Shared_Ptr(Shared_Ptr const& ptr) {}
	
	//泛华copy构造函数
	template<typename Y>
	Shared_Ptr(Shared_Ptr<Y> const& ptr) {}
};

/*
int main() {
	//SmartPtr45<Top> pt1 = SmartPtr45<Middle>(new Middle); 这行代码报错的原因，因为模板具现化时并不知道二者有继承关系
	SmartPtr245<Top> pt1 = SmartPtr245<Middle>(new Middle);
	SmartPtr245<Middle> pt2 = SmartPtr245<Top>(new Top);//这个居然也通过了编译，灾难！
	SmartPtr345<Top> pt3 = SmartPtr345<Middle>(new Middle);
}
*/

/*
总结
1.请使用 member function templates（成员函数模板）生成“可接受所有兼容类型” 的函数。
2.如果你声明 member templates  用千＂泛化copy 构造”或“泛化assignment 操作“, 你还是需要声明正常的copy构造函数和 copy assignment 操作符。

*/