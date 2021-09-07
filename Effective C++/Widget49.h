#include<new>
#include<iostream>

class NewHandlerHolder{
public:
	explicit NewHandlerHolder(std::new_handler nh) :handler(nh) {}
	//�����������ڻָ�handler
	~NewHandlerHolder() { std::set_new_handler(handler); }
private:
	std::new_handler handler;
	//��ֹcopy
	NewHandlerHolder(const NewHandlerHolder&);
	NewHandlerHolder& operator=(const NewHandlerHolder&);
};

//Ϊÿһ�������������е�new_handler
class Widget49 {
public:
	static std::new_handler set_new_handler(std::new_handler p)throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;//����ԭ�е�new_handler
};