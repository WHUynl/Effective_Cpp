#include"Widget49.h"

std::new_handler Widget49::currentHandler = 0;

std::new_handler Widget49::set_new_handler(std::new_handler p)throw() {
	std::new_handler oldHandler = currentHandler;//保存原有的handler
	currentHandler = p;//设置新的handler
	return oldHandler;//返回值为旧的handler
}

/*
重载的new需要干的事
1.调用标准 set_new_handler
2.调用 global operator new
3.如果成功分配new会返回指向分配内存地址的指针，其会自动恢复原来的new_handler
*/

void* Widget49::operator new(size_t size) throw(std::bad_alloc) {
	NewHandlerHolder h(std::set_new_handler(currentHandler));//将handler设置为了 Widget的handler,同时也保存了旧的handler
	return ::operator new(size);
}