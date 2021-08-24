//宁以non-member、non-friend 替换 memeber

/*
member可以访问private的成员，从而导致封装性减弱
C++中，将这类函数可以与对应的class放到一个namespace内
因为namespace 可以跨文件，故以后可以在其他功能的文件中，也可以
继续使用该namespace 
*/

namespace WebBrowserStuff{
	class WebBrowser {};
	void clearBrowser(WebBrowser& wb) {}
}

/*
总结
宁可拿non-member non-friend 函数替换 member 函数。这样做可以增加封装性、包裹弹性（packaging flexibility ) 和机能扩充性。
*/

