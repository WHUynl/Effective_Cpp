#include<new>
#include<iostream>

class NewHandlerHolder{
public:
	explicit NewHandlerHolder(std::new_handler nh) :handler(nh) {}
	//析构函数用于恢复handler
	~NewHandlerHolder() { std::set_new_handler(handler); }
private:
	std::new_handler handler;
	//阻止copy
	NewHandlerHolder(const NewHandlerHolder&);
	NewHandlerHolder& operator=(const NewHandlerHolder&);
};

//为每一个类添加自身独有的new_handler
class Widget49 {
public:
	static std::new_handler set_new_handler(std::new_handler p)throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;//保存原有的new_handler
};