//�˽�C++ĬĬ��д��������Щ����


//���������Զ���������һϵ�к�����������
class Empty {};//�ȼ���
/*
class Empty{
public:
	Empty(){....}
	Empty(const Empty& rhs){...}
	-Empty(){...}
	Empty& operator=(const Empty& rhs){....}
};
*/

//��ע�Ⲣ����������Ķ����Զ����ɣ����纬��const��Ա����references��Աʱ��
class  MyClass
{
public:
	 MyClass( int ctmp,int& rtmp);

private:
	const int constTmp;
	int& reference;
};

MyClass::MyClass( int ctmp, int& rtmp) :constTmp(ctmp), reference(rtmp){
}

/*
int main() {
	int a = 10;
	int b = 12;
	MyClass my1(10, a);
	MyClass my2(12, b);
	//my1 = my2; ��仰������ ��Ϊ������ԭ��Ĭ��copy��ֵ���������ڱ�����������

}
*/

/*
�ܽ�
1.���������԰���Ϊclass����default���캯����copy���캯����copy assignment ���������Լ�����������
*/