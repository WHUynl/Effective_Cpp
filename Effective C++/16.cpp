//�ɶ�ʹ��new��deleteʱҪ��ȡ��ͬ��ʽ

#include<iostream>
using namespace std;
typedef string Addressline[4];

void deleteFunc() {
//ע��new[] �� delete[]�ĳɶ�ʹ�ã��������С��typdef ����������
	string* pal = new Addressline;
	//delete pal; ��Ϊδ����!
	delete[] pal;//�������ȷ��
}

/*
�ܽ�
1.�������new���ʽ��ʹ��[], ��������Ӧ��delete���ʽ��Ҳʹ��[]�� ������� new ���ʽ�в�ʹ�ãۣݣ�һ����Ҫ����Ӧ��delete���ʽ��ʹ��[]��
*/