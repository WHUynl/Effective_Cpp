//����non-member��non-friend �滻 memeber

/*
member���Է���private�ĳ�Ա���Ӷ����·�װ�Լ���
C++�У������ຯ���������Ӧ��class�ŵ�һ��namespace��
��Ϊnamespace ���Կ��ļ������Ժ�������������ܵ��ļ��У�Ҳ����
����ʹ�ø�namespace 
*/

namespace WebBrowserStuff{
	class WebBrowser {};
	void clearBrowser(WebBrowser& wb) {}
}

/*
�ܽ�
������non-member non-friend �����滻 member �������������������ӷ�װ�ԡ��������ԣ�packaging flexibility ) �ͻ��������ԡ�
*/

