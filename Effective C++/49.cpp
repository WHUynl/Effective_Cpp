//�˽�new-handler����Ϊ
#include"Widget49.h"
/*
��operator new�׳��쳣��ʱ�򣬱�����һ���ͻ�
ָ���Ĵ���������һ����ν��new-handler��Ϊ��ָ��
��new-handler���ͻ���Ҫ����<new>��һ����׼����⺯��

namespace std{
typedef void (*new_handler)();
new_handler set_new_handler(new_handler p) throw();
}

*/

void outOfMem() {
	std::cerr << "Unable to satisfy request for memory\n";
	std::abort();
}

/*
ע�⣬���ڴ��޷������ʱ�򣬻�һֱ����new_handler��֪�����䵽�ڴ档
һ�������new_handler��Ҫ���㣺
1.�ø����ڴ�ɱ�ʹ��
2.��װ��һ��new_handler
3.ж��new_handler
4.�׳�bad_alloc���쳣
5.�����أ�ͨ������abort��exit��
*/



int main() {
	std::set_new_handler(outOfMem);
	// int(* pBigDataArray)[100000L] = new int[10000L][100000L]; ������õ�outOfMem
	Widget49::set_new_handler(outOfMem);
	Widget49* pw1 = new Widget49;
	Widget49::set_new_handler(0);
	Widget49* pw2 = new Widget49;
}

/*
�ܽ�
1.set _new_handler ����ͻ�ָ��һ�����������ڴ�����޷��������ʱ�����á�
2.Nothrow new ��һ����Ϊ���޵Ĺ��ߣ���Ϊ��ֻ����ǧ�ڴ���䣻��̵Ĺ��캯�����û��ǿ����׳��쳣��

*/