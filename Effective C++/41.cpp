//�˽���ʽ�ӿںͱ����ڶ�̬

/*
��Template�����Ա�̵��������ʽ�ӿ�
�Լ������ڶ�̬�Եø�Ϊ��ҪһЩ��
ʾ�����£�
*/

template <typename T>
static void doSomething(T& w) {
	if (w.size() > 10) {
		T temp(w);
		temp.normalize();
		temp.swap(w);
	}
}

/*
ʾ��������
1.w�Ǳ���֧�ֲ��ֽӿڵģ����ֲ����ں���ǩ��ʽ��
������Ч���ʽ��ɣ�������ʽ�ӿڡ�
2."�Բ�ͬ��template�������ֻ�function templates"�ᵼ��
���ò�ͬ�ĺ���������Ǳ����ڶ�̬��
*/

/*
1.classes �� templates��֧�ֽӿ�(interfaces)�Ͷ�̬(polymorphism) ��
2.�� classes ���Խӿ�����ʽ��( explicit)���Ժ���ǩ��Ϊ���ġ���̬����ͨ��virtual
���������������ڡ�
3.��template�������ԣ��ӿ�����ʽ�� (implicit ) ���������Ч���ʽ��
��̬����ͨ��template���ֻ��ͺ������ؽ���(function overloading resolution) �����ڱ����ڡ�
*/