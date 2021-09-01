//了解隐式接口和编译期多态

/*
在Template及泛性编程的世界里，隐式接口
以及编译期多态显得更为重要一些。
示例如下：
*/

template <typename T>
static void doSomething(T& w) {
	if (w.size() > 10) {
		T temp(w);
		temp.normalize();
		temp.swap(w);
	}
}

/*
示例代码中
1.w是必须支持部分接口的，这种不基于函数签名式，
而是有效表达式组成，便是隐式接口。
2."以不同的template参数具现化function templates"会导致
调用不同的函数，这就是编译期多态。
*/

/*
1.classes 和 templates都支持接口(interfaces)和多态(polymorphism) 。
2.对 classes 而言接口是显式的( explicit)，以函数签名为中心。多态则是通过virtual
函数发生于运行期。
3.对template参数而言，接口是隐式的 (implicit ) ，奠基于有效表达式。
多态则是通过template具现化和函数重载解析(function overloading resolution) 发生于编译期。
*/