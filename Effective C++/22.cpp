//将成员变置声明为private

class AccessLevels {
public:
	int getReadOnly() const { return readOnly; }
	void setReadWrite(int value) { readWrite = value; }
	int getReadWrite() const { return readWrite; }
	void setWriteOnly(int value) { writeOnly = value; }
private:
	int noAccess;//对此int无任何访问动作
	int readOnly;//对此int做只读访问(read-only access)
	int readWrite;//对此int做读写访问(read-write access)
	int writeOnly;//对此int做惟写访问C write-only access)
};

/*
从上述的代码中，我们可以看出所有成员变量均被设置为private的优势在于
可以自如的设置成员变量为“不准访问”，“只读访问”，“读写访问”，甚至
“唯写访问”。这正是封装所需要的
*/

/*
总结
1.切记将成员变量声明为private。这可赋予客户访问数据的一致性、可细傲划分访问控制、允诺约束条件获得保证，并提供class 作者以充分的实现弹性。
2.protected 并不比 public 更具封装性。

*/