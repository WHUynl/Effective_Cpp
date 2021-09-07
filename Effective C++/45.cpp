//����45 ���ó�Ա����ģ��������м�������
#include<iostream>
#include<string>
using namespace std;

class Top{};
class Middle:public Top{};

template<typename T>
class SmartPtr45 {
public:
	explicit SmartPtr45(T* realPtr) :dataPtr(realPtr) {}
private:
	T* dataPtr;
};

template<typename T>
class SmartPtr245 {
public:
	explicit SmartPtr245(T* realPtr) :dataPtr(realPtr) {}
	/*
	����copy���캯��,�ð汾�����и�����
	���ǲ��ò��� Top��Middle���ɵ�������֡�
	*/
	template<typename U>
	SmartPtr245(const SmartPtr245<U>& other) {}
	T* dataPtr;
};

template<typename T>
class SmartPtr345 {
public:
	explicit SmartPtr345(T* realPtr) :dataPtr(realPtr) {}
	/*
	����copy���캯��,�ð汾�����и�����
	*/
	template<typename U>
	//ʹ�ó�Ա��ֵ�б�ķ�������������ʾ��ʹ��U*ָ��ΪT*ָ�븳ֵ���Լ�get()�������ñ�������������⡣
	SmartPtr345(const SmartPtr345<U>& other) : dataPtr(other.get()) {}
	T* get() const{ return dataPtr; }
private:
	T* dataPtr;
};

/*
����ע�⣬����ʹ���˳�Ա����ģ��������Ĭ�Ϻ�����
����Ҳ��Ҫ�Լ��ֶ����壬������������ǻ��Զ����ɡ�
*/

template<typename T>
class Shared_Ptr {

	//copy���캯��
	Shared_Ptr(Shared_Ptr const& ptr) {}
	
	//����copy���캯��
	template<typename Y>
	Shared_Ptr(Shared_Ptr<Y> const& ptr) {}
};

/*
int main() {
	//SmartPtr45<Top> pt1 = SmartPtr45<Middle>(new Middle); ���д��뱨���ԭ����Ϊģ����ֻ�ʱ����֪�������м̳й�ϵ
	SmartPtr245<Top> pt1 = SmartPtr245<Middle>(new Middle);
	SmartPtr245<Middle> pt2 = SmartPtr245<Top>(new Top);//�����ȻҲͨ���˱��룬���ѣ�
	SmartPtr345<Top> pt3 = SmartPtr345<Middle>(new Middle);
}
*/

/*
�ܽ�
1.��ʹ�� member function templates����Ա����ģ�壩���ɡ��ɽ������м������͡� �ĺ�����
2.��������� member templates  ��ǧ������copy ���족�򡰷���assignment ������, �㻹����Ҫ����������copy���캯���� copy assignment ��������

*/