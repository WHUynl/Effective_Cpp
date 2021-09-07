#include"Widget49.h"

std::new_handler Widget49::currentHandler = 0;

std::new_handler Widget49::set_new_handler(std::new_handler p)throw() {
	std::new_handler oldHandler = currentHandler;//����ԭ�е�handler
	currentHandler = p;//�����µ�handler
	return oldHandler;//����ֵΪ�ɵ�handler
}

/*
���ص�new��Ҫ�ɵ���
1.���ñ�׼ set_new_handler
2.���� global operator new
3.����ɹ�����new�᷵��ָ������ڴ��ַ��ָ�룬����Զ��ָ�ԭ����new_handler
*/

void* Widget49::operator new(size_t size) throw(std::bad_alloc) {
	NewHandlerHolder h(std::set_new_handler(currentHandler));//��handler����Ϊ�� Widget��handler,ͬʱҲ�����˾ɵ�handler
	return ::operator new(size);
}