//请使用traits classes表现类型信息

/*
STL里面含有5种迭代器
1.input迭代器：只向前，一次一步，只读取且一次。
2.output迭代器：只向前，一次一步，只涂改且一次
3.forward迭代器：前两者+可读写多次
4.bidirectional迭代器：forward+甚至可以向后移动。
5.random_access迭代器:随机访问的支持。

下述关系非常容易得到：
struct intput_iterator_tag{};
struct output_iteratoe_tag{};
struct forward_iterator_tag{}:public input_iterator_tag{};
struct bidirectional_iterator_tag:forward_iterator_tag{}；
struct random_access_iterator_tag:public bidirectional_iterator_tag{}

所以我们希望实现的 advance 如下所示
template<typename IterT,typename DistT>
void advance(IterT& iter,DistT d){
	if(iter is a random access iterator) {
		iterT += d;
	}else{
		if(d >0){while(d--)++iter;}
		else{while(d++)--iter; }
		}
}
综上可知，我们希望在编译期就知道获取类型的信息，这正是Traits技术所提供的
*/

/*
Traits技术要求：
1.对内置类型必须和自定义类型效果一致，如上述传入参数类型为const char* 和 int,
故我们无法将信息嵌套于原始指针内。
所以解决的方法如下：
A.对于自定义对象：
在自定义类型中
template<...>
class deque{
public:
	class iterator{
	public:
		typedef random_access_iterator_tag iterator_category;
	};
};

在iterator_traits 中
template<typename IterT>
structr iterator_traits{
		typedef typename IterT::iterator_category iterator_category;  
};
B.对于内置类型则需要使用偏特化
template<typename IterT>
structr iterator_traits<IterT*>{
		typedef  random_access_iterator_tag iterator_category;
};

很棒，但遗憾的是注意先前的伪代码中，
	if(iter is a random access iterator)
这段话依旧是在运行过程中，确定是否成立，并没有达到预期

所以更正确的做法应该如下所示


template<typename IterT, typename DistT>
void doAdvance(IterT& iter,DistT d,std::random_access_iterator_tag){
iter+=d;
}
后面的略去

 template<typename IterT,typename DistT>
 void advance(IterT& iter,DistT d){
	doAdvance(iter.d.typename std::iterator_traits<IterT>::iterator_category());
 }

 总的来说：
 1.建立重载函数或者模板函数（doAdvance)，彼此间的差距只有各自的traits参数 （服务的实现）
 2.建立一个控制函数或函数模板（advance）,其负责调用上述的函数，并传递traits classes信息。
*/

/*
总结
1.Traits classes使得“类型相关信息”在编译器可用。它们以templates和“templates特化”完成实现。
2.整合重载技术后，traits classses有可能在编译期对类型执行if...else测试。
*/