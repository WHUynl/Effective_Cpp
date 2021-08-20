//��operator=����һ��reference to *this�Լ�����"���Ҹ�ֵ"
/*
��ֵ������ʽ
int x,y,z;
x = y = z = 15;��������
x = (y = (z = 15)); �ҽ��
*/

class Bitmap{};
class Widget {
public:
	Widget& operator=(const Widget& rhs) {
		//���е�copy��ֵ����Ҫ���ǵ�������ǣ����Ҹ�ֵ�����⣬����delete����ŵ����
		if (this == &rhs) {
			return *this;
		}
		Bitmap* pOrig = pb;
		pb = new Bitmap(*rhs.pb);
		delete pOrig;
		return *this;//�Ե�ǰ������ɲ�����Ӧ�÷���������
	}
private:
	Bitmap* pb;
};

/*
�ܽ�
1.�ֵ( assignment)����������һ��reference to *this��
2.ȷ�����������Ҹ�ֵʱoperator= ��������Ϊ�����м��������Ƚϡ���Դ���� �͡�Ŀ����󡱵ĵ�ַ�������ܵ������˳���Լ� copy-and-swap.
3.ȷ���κκ����������һ�����ϵĶ��󣬶����ж��������ͬһ������ʱ������Ϊ��Ȼ��ȷ��
*/