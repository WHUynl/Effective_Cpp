//���뷵�ض���ʱ�������뷵����reference
class Rational
{
public:
	Rational(int num=0,int den=1);

private:
	int n,d;

	friend const Rational operator* (const Rational& lhs, const Rational& rhs);//��ȷ�İ汾
};

Rational::Rational(int num = 0, int den = 1):n(num),d(den)
{
}

//��ȷ�汾
const Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
	return result;
}
//�������ľ�Ϊ���ѵ�ʵ�ַ�ʽ
/*
1.���ط�ʽǿ��ʹ��ref
ԭ��result���������ڴ���stack�������� * �ĺ����������ڴ汻�Զ��ջأ��򷵻صĵ�ַ��ʮ��Σ��
friend const Rational& operator*(const Rational& lhs, const Rational& rhs){
	Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
	return result;
}
----------------------------------------------------------------------------
2.�ڵ�һ���У�ʹ���ɵ�result��һ��ָ��
ԭ���ڴ�й© �� Rational d=a*b*cʱ�����д��������2��new!ȴû��delete
friend const Rational& operator*(const Rational& lhs, const Rational& rhs){
	Rational* result=new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	return *result;
}
----------------------------------------------------------------------------
3.ʹ��static��������ֵ��֤��ȫ���ڴ棬
ԭ��(a*b)==(c*d)��ֵ����ԶΪ�棬��Ϊ����ֵ��Զ��static Rational ��ǰ��ֵ��
friend const Rational& operator*(const Rational& lhs, const Rational& rhs){
	static Rational result;
	result = Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	return result;
}
*/

/*
�ܽ�
����Ҫ����pointer�� reference ָ��һ�� local stack ���󣬻򷵻� reference ָ��һ��heap-allocated ����
�򷵻� pointer �� reference ָ��һ��local static ������п���ͬʱ��Ҫ��������Ķ���
���� 4 �Ѿ�Ϊ���ڵ��̻߳����к����� reference ָ��һ�� local static �����ṩ��һ�����ʵ����
*/