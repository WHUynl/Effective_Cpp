//�Զ�����佫newed������������ָ��
#include<iostream>
using namespace std;
class Widget {};

int priority() { return 0; }
void processWidget(shared_ptr<Widget> pw, int priority) {}

void notGood() {
//һ�����淶�Ĵ����д������ʾ��
	processWidget(shared_ptr<Widget>(new Widget), priority());
/*
����������,����������˳��
��	ִ�� "new  Widget"
��	���� shared_ptr �Ĺ��캯��
��  ���� priority()
-------------------------------
��ʵ�ʵ�˳��ȱʧ����ģ��п�����
��	ִ�� "new  Widget"
��  ���� priority()
��	���� shared_ptr �Ĺ��캯��
��ô������� priority�����쳣�����п��ܵ���new���ڴ�й©����Ϊ��ָ�붪ʧ��
*/
//���ʵĵ���
	shared_ptr<Widget> pw(new Widget);
	processWidget(pw, priority());

}
/*
�ܽ�
1.�Զ�����佫 newed ����洢�ڣ����룩����ָ���ڡ��������������һ���쳣���׳����п��ܵ������Բ������Դй©��

*/