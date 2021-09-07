/*
template�������붨���Ӧ�÷�����ͷ�ļ��У��������ļ�����Ϊhpp
�����й�����Ԫ���������������˼����
1.Ϊ����Ԫ�Ϸ����������template<typename>
2.Ϊ����Ԫ�������������ڶ���


1.������ʹ����Ԫ���������ɾ���Ϊ�ˣ�����ģ����ֻ���ʱ��ֱ�ӣ��ƶϳ�
��Ԫ�����Ĳ���T�����ͣ��Ӷ��������һ������ 2 ��ʱ�������ֱ�ӽ������
��ʽת������ 2 -> RationReal<int>,������template<typename>������Ԫ����
�����ٽ����Զ������ƶϡ�

2.��Ϊ��Ԫ�����������template<typename>���Ӷ�����������ν����Ԫ�����ġ����塱
���޷������ڵ���Ԫ����ƥ���ϵģ���ֻ�ܽ�����д�����ڣ�����Ԫ�������inline��
*/
template<typename T>
class RationalReal
{
public:
	RationalReal(const T num = 0, const T den = 1):n(num),d(den) {}
	const T num() const { return n; }
	const T den() const { return d; }
private:
	T n;
	T d;

	friend const RationalReal operator* (const RationalReal& lhs, const RationalReal& rhs) {
		return doMultiply(lhs, rhs);
	}
};

template<typename T>
const RationalReal<T> doMultiply(const RationalReal<T>& lhs, const RationalReal<T>& rhs) {
	return RationalReal<T>(lhs.num() * rhs.num(), rhs.den() * lhs.den());
}


