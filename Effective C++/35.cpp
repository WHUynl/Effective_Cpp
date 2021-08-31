//����virtual�������������ѡ��
#include<iostream>
#include<functional>
class GameCharacter {
public:
	//��������Ľ���ָ����derived classes�����¶�����
	virtual int healthValue() const {}
};

//1.����Non-Virtual Interface�ַ�ʵ��Template Methodģʽ
//ģ����ƣ�ʹ�ͻ�ͨ��public�ӿڣ���ӵ���private virtual����
class GameCharacter1 {
public:
	int healthValue() const {
		int retVal = doHealthValue();//thisָ��ʡ�ԣ�ʹ�麯��������Ч
		return retVal;
	}
private://��ʱ����Ҫprotected
	//derived class�����¶������ֵ
	virtual int doHealthValue() const { return 1; }
};

//2.����Function Pointersʵ��Strategyģ��
//���Է�ʽ����֤��ͬһ��GameCharacter2����ʹ�ò�ͬ�Ĳ��ԣ����Խ��и�����
class GameCharacter2;
//���º����Ǽ��㽡��ָ����ȱʡ�㷨
int defaultHealthCalc(const GameCharacter2& gc) { return 2; }
class GameCharacter2 {
public:
	typedef int (*HealthCalcFunc)(const GameCharacter2&);
	explicit GameCharacter2(HealthCalcFunc hcf = defaultHealthCalc):healthFunc(hcf){}
	int healthValue() const { return healthFunc(*this); }
private:
	HealthCalcFunc healthFunc;
};

//3.���� trl::function���Strategyģʽ
class   GameCharacter3;
int	defaultHealthCalc3(const GameCharacter3& gc) { return 3; }
class GameCharacter3{
public:
	//HealthCalcFunc �������κΡ��ɵ���� (callable entity) , �ɱ����ò�����
	//�κμ�����GameCharacter ֮������κμ�����int �Ķ��������¡�
	typedef  std::function<int(const GameCharacter3&)> HealthCalcFunc;
	explicit GameCharacter3(HealthCalcFunc hcf = defaultHealthCalc3):healthFunc(hcf){ }
	int healthValue()  const
	{
		return  healthFunc(*this);
	}

private:
	HealthCalcFunc healthFunc;
};

//4.�ŵ��Strategyģʽ
//��Ϥ��׼Strategyģʽ���˺����ױ����������������ṩ����һ�����еĽ����㷨����ʹ�á��Ŀ�����
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
�ܽ�
1.virtual ����������������� NVI �ַ��� S tra tegy ���ģʽ�Ķ�����ʽ��NVI �ַ�������һ��������ʽ�� Template Me thod ���ģʽ��
2.�����ܴӳ�Ա�����Ƶ� class �ⲿ������������һ��ȱ���ǣ��ǳ�Ա�����޷����� class ��non-pub lic ��Ա��
3.trl::function�������Ϊ����һ�㺯��ָ�롣�����Ķ���ɽ��������֮
Ŀ��ǩ��ʽ ( target signature) ���ݡ������пɵ����� ( callableentities)  ��


*/