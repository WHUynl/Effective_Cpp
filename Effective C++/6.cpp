//������ʹ�ñ������Զ����ɵĺ������͸���ȷ�ܾ�


//�̳�Uncopyable���Խ�����ʱ��������ǰ�Ƶ�������
class Uncopyable {
protected:
	Uncopyable() {} //����derived�����������
	~Uncopyable() {}
private:
	Uncopyable(const Uncopyable&);//����֯copy
	Uncopyable& operator= (const Uncopyable&);
};

class HomeForSale :private Uncopyable {
	//class�ڲ�������copy���캯����copy assign. ������
};

/*
�ܽ�
1.Ϊ���ر������Զ������ԣ��ṩ�Ļ��ܣ��ɽ���Ӧ�ĳ�Ա��������Ϊprivate ���Ҳ���ʵ�֡�ʹ����Uncopyable������ base class Ҳ��һ��������
*/
