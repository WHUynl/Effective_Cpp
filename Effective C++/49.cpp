//了解new-handler的行为
#include"Widget49.h"
/*
当operator new抛出异常的时候，便会调用一个客户
指定的错误函数处理，一个所谓的new-handler。为了指定
该new-handler，客户需要调用<new>的一个标准程序库函数

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
注意，当内存无法分配的时候，会一直调用new_handler，知道分配到内存。
一个合理的new_handler需要满足：
1.让更多内存可被使用
2.安装另一个new_handler
3.卸载new_handler
4.抛出bad_alloc的异常
5.不返回（通常调用abort或exit）
*/



int main() {
	std::set_new_handler(outOfMem);
	// int(* pBigDataArray)[100000L] = new int[10000L][100000L]; 将会调用到outOfMem
	Widget49::set_new_handler(outOfMem);
	Widget49* pw1 = new Widget49;
	Widget49::set_new_handler(0);
	Widget49* pw2 = new Widget49;
}

/*
总结
1.set _new_handler 允许客户指定一个函数，在内存分配无法获得满足时被调用。
2.Nothrow new 是一个颇为局限的工具，因为它只适用千内存分配；后继的构造函数调用还是可能抛出异常。

*/