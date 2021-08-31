//���Ƕ�������ʹ��private�̳�
#include<iostream>
using namespace std;
/*
private�̳���ζis-implemented-in-terms-of�븴����һ�µģ����ȡ���أ�
������ʹ�ø��ϣ���Ҫʱ������private�̳С���ʱΪ��Ҫ�أ�
��protected��Ա��virtualǣ����ʱ��Ϊ��Ҫ��
*/

//�ٶ��������������WidgetҪʹ��Timer
class Timer {
public:
	virtual void onTick() const;//��ʱ������
};

//һ����ͨ��ƣ�ֻ��ʹ��private�̳У������¶��庯��
class Widget39_1 :private Timer {
private:
	virtual void onTick() const { cout << "Widget39_1��onTick"<<endl; }
};

/*
��ȷ�������ʹ���������public�̳���ʵ��,�ŵ�
1.���Ա�֤Widget��derived�಻�������¶���onTick
2.���ͱ���������
*/
class Widget39_2 {
private:
	class WidgetTimer :public Timer {
	public:
		virtual void onTick() const { cout << "WidgetTimer��onTick" << endl; }
	};
	WidgetTimer timer;
};

//private��ʹ��ԭ�������
// 
//û�����ݣ����Զ���Ӧ�ò�ʹ���κ��ڴ�
class Empty {
	/*
	һ��Ậ��typedef��enums,static��Ա��������non-virtual����
	*/
};

class HoldsAnInt {
private:
	int x;
	Empty e;//�����ϲ�Ӧ��ռ���ڴ棬����ռ����1��
};

class HoldsAnInt2 :private Empty {//��ʱ�ͽ�ʡ���ڴ�
	int x;
};

/*
�ܽ�
1.Private �̳���ζis-implemented- in-termsof������ĳ��ʵ�ֳ�������ͨ���ȸ���( composition)�ļ���͡�
���ǵ�derived class ��Ҫ����protected base class �ĳ�Ա������Ҫ���¶���̳ж�����virtual ����ʱ����ô����Ǻ���ġ�
2.�͸��� (composition) ��ͬ��private �̳п������empty base ���Ż���
��������ڡ�����ߴ���С�����ĳ���⿪���߶��ԣ����ܺ���Ҫ��
*/