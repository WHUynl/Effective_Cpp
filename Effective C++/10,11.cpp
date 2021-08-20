//令operator=返回一个reference to *this以及处理"自我赋值"
/*
赋值连锁形式
int x,y,z;
x = y = z = 15;本质如下
x = (y = (z = 15)); 右结合
*/

class Bitmap{};
class Widget {
public:
	Widget& operator=(const Widget& rhs) {
		//所有的copy赋值都需要考虑的问题就是，自我赋值的问题，所以delete必须放到最后。
		if (this == &rhs) {
			return *this;
		}
		Bitmap* pOrig = pb;
		pb = new Bitmap(*rhs.pb);
		delete pOrig;
		return *this;//对当前对象完成操作后，应该返回左侧对象
	}
private:
	Bitmap* pb;
};

/*
总结
1.令赋值( assignment)操作符返回一个reference to *this。
2.确保当对象自我赋值时operator= 有良好行为。其中技术包括比较”来源对象” 和“目标对象”的地址、精心周到的语句顺序、以及 copy-and-swap.
3.确定任何函数如果操作一个以上的对象，而其中多个对象是同一个对象时，其行为仍然正确。
*/