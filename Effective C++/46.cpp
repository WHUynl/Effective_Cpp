//��Ҫ����ת��ʱ��Ϊģ�嶨��ǳ�Ա����

/*
����24 �Ѿ�˵����non-member����ʵʩ��ʽ����ת����
*/

template<typename T>
class Rational46 {
public:
	Rational46(const T& n = 0, const T& d = 1) :numerator(n), denominator(d) {}
	const T num() const{ return numerator; }
	const T den() const { return denominator; }


private:
	T numerator;
	T denominator;
};

template<typename T>
const Rational46<T> operator* (const Rational46<T>& lhs, const Rational46<T>& rhs) {
	Rational46<T> result(lhs.num(), rhs.den());
	return result;
}

/*
��ϸ����ȷ���ݣ��Լ�һЩ˼���ͷ�˼��
��Rational46.hpp
*/

/*
int main() {
	Rational46<int> oneHalf(1, 2);//û����
	//Rational46<int> answer = oneHalf * 2; ���������ˣ�2���޷���ʼ��ģ��ġ���Ϊtemplateʵ���Ƶ������дӲ�����ʽ����ת���������뿼�ǡ�
}
*/

/*
�ܽ�
�����Ǳ�дһ�� class template, �������ṩ֮ �����template ��صģ�
����֧�֡����в���֮��ʽ����ת����ʱ��
�뽫��Щ��������Ϊ �� class template �ڲ��ģ�inline�� friend ��������
*/