//考虑virtual函数以外的其他选择
#include<iostream>
#include<functional>
class GameCharacter {
public:
	//返回人物的健康指数；derived classes可重新定义它
	virtual int healthValue() const {}
};

//1.藉由Non-Virtual Interface手法实现Template Method模式
//模板设计：使客户通过public接口，间接调用private virtual函数
class GameCharacter1 {
public:
	int healthValue() const {
		int retVal = doHealthValue();//this指针省略，使虚函数机制生效
		return retVal;
	}
private://有时候需要protected
	//derived class来重新定义这个值
	virtual int doHealthValue() const { return 1; }
};

//2.藉由Function Pointers实现Strategy模板
//策略方式，保证了同一个GameCharacter2可以使用不同的策略，可以进行更换。
class GameCharacter2;
//以下函数是计算健康指数的缺省算法
int defaultHealthCalc(const GameCharacter2& gc) { return 2; }
class GameCharacter2 {
public:
	typedef int (*HealthCalcFunc)(const GameCharacter2&);
	explicit GameCharacter2(HealthCalcFunc hcf = defaultHealthCalc):healthFunc(hcf){}
	int healthValue() const { return healthFunc(*this); }
private:
	HealthCalcFunc healthFunc;
};

//3.藉由 trl::function完成Strategy模式
class   GameCharacter3;
int	defaultHealthCalc3(const GameCharacter3& gc) { return 3; }
class GameCharacter3{
public:
	//HealthCalcFunc 可以是任何“可调用物” (callable entity) , 可被调用并接受
	//任何兼容于GameCharacter 之物，返回任何兼容于int 的东西。详下。
	typedef  std::function<int(const GameCharacter3&)> HealthCalcFunc;
	explicit GameCharacter3(HealthCalcFunc hcf = defaultHealthCalc3):healthFunc(hcf){ }
	int healthValue()  const
	{
		return  healthFunc(*this);
	}

private:
	HealthCalcFunc healthFunc;
};

//4.古典的Strategy模式
//熟悉标准Strategy模式的人很容易辨认它，而且它还提供“将一个既有的健康算法纳入使用”的可能性
class GameCharacter4; 
class HealthCalcFunc4 {
public:
	virtual int calc(const GameCharacter4& gc) const { return 4; }
};
HealthCalcFunc4 defaultHealthCalc4; 
class GameCharacter4{
public:
	explicit GameCharacter4(HealthCalcFunc4* phcf = &defaultHealthCalc4):pHealthCalc(phcf){}
	int healthValue()  const{
		return pHealthCalc->calc(*this);
	}
private:
	HealthCalcFunc4* pHealthCalc;
};

/*
总结
1.virtual 函数的替代方案包括 NVI 手法及 S tra tegy 设计模式的多种形式。NVI 手法自身是一个特殊形式的 Template Me thod 设计模式。
2.将机能从成员函数移到 class 外部函数，带来的一个缺点是，非成员函数无法访问 class 的non-pub lic 成员。
3.trl::function对象的行为就像一般函数指针。这样的对象可接纳与给定之
目标签名式 ( target signature) 兼容”的所有可调用物 ( callableentities)  。


*/