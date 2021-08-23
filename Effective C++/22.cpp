//����Ա��������Ϊprivate

class AccessLevels {
public:
	int getReadOnly() const { return readOnly; }
	void setReadWrite(int value) { readWrite = value; }
	int getReadWrite() const { return readWrite; }
	void setWriteOnly(int value) { writeOnly = value; }
private:
	int noAccess;//�Դ�int���κη��ʶ���
	int readOnly;//�Դ�int��ֻ������(read-only access)
	int readWrite;//�Դ�int����д����(read-write access)
	int writeOnly;//�Դ�int��Ωд����C write-only access)
};

/*
�������Ĵ����У����ǿ��Կ������г�Ա������������Ϊprivate����������
������������ó�Ա����Ϊ����׼���ʡ�����ֻ�����ʡ�������д���ʡ�������
��Ψд���ʡ��������Ƿ�װ����Ҫ��
*/

/*
�ܽ�
1.�мǽ���Ա��������Ϊprivate����ɸ���ͻ��������ݵ�һ���ԡ���ϸ�����ַ��ʿ��ơ���ŵԼ��������ñ�֤�����ṩclass �����Գ�ֵ�ʵ�ֵ��ԡ�
2.protected ������ public ���߷�װ�ԡ�

*/