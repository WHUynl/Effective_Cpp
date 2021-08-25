//���ļ���ı��������ϵ�������

/*
ʹ��interface class��һ��������ʹ�ó�����࣬��ͻ���Ҫʹ��Person��pointers����references
��Ϊ��������ԡ��ں�pure virtual��������Person classes���ֳ�ʵ�塣
����� 31Person ��31RealPerson
*/
#include"31Person.h"

/*
ʹ�ø÷���Ҫע�����
1.�ӿ���Ӧ�Ƕ����г�Ա������Ϊ���麯����������һ������ָ���static��������������������
2.��Ϊ�����Ķ�����Person�������ģ�������Ҫʵ���࣬����ذ������ߵ�ͷ�ļ�
3.�ͻ�ʹ��ʱ�ض�Ҫ��pointer����ʽ

�ô�������������
�Ӵ˶�RealPerson�����޸�ʱ��ֻ��Ҫ���±�����������ļ����ɣ���粻���֪
*/


int main() {
	string name = "ynl";
	shared_ptr<Person> pp = Person::createPerson(name);
	cout << pp->name() << endl;
}

/*
�ܽ�
1.֧�֡�������������С������һ�㹹���ǣ�����������ʽ����Ҫ�����ڶ���ʽ�����ڴ˹���������ֶ��� Handle classes �� Interface classes��
2.�����ͷ�ļ�Ӧ���ԡ� ��ȫ�ҽ�������ʽ�� ( full and declaration-only forms) ����ʽ���ڡ��������������Ƿ��漰templates������
*/
