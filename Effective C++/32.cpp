//ȷ�����public�̳���ģ��is-a��ϵ
/*
ÿһ����Baseʵ�ֵĹ�����ÿ��Derived�о�����ʵ�֣�
����ע�⣬������ܻ�ȽϷ�ֱ���������·����κ������ε�����
*/

#include <cassert>
class Rectangle {
public:
	virtual void setHeight(int H) { height = H; }
	virtual void setWidth(int W) { width = W; }
	virtual int heightValue() const { return height; }
	virtual int widthValue() const { return width; }
private:
	int height;
	int width;
};

/*
���δ�����������þ��εĿ��10����֤���εĸ߶Ȳ��䣬����ʹ�ö��Խ�������
Ȼ����������������εĻ���Ĵ�����ƻ���������ԭ�еķ���
*/

void makeBigger(Rectangle& r) {
	int oldHeight = r.heightValue();
	r.setWidth(r.widthValue() + 10);
	assert(r.heightValue() == oldHeight);
}

/*
�ܽ�
"public�̳�"��ζis-a��������base classes���ϵ�ÿһ������ һ��Ҳ������
derived classes ���ϣ���Ϊÿһ��derived class����Ҳ����һ��base class����

*/