//���Ƕ�������ʹ�ö��ؼ̳�

/*
��File��һ����Ա���� filename,���������·����
IOFile��2��filename�Ƿ���Υ��ʶ����ʹ��InputFile::�������
�������ʹ��virtual�̳�
*/

class File {};
class InputFile:virtual public File{};
class OutputFile:virtual public File{};
class IOFile :public InputFile, public OutputFile {};

/*
�ܽ�
1.���ؼ̳бȵ�һ�̳и��ӡ������ܵ����µ������ԣ��Լ���virtual�̳е���Ҫ��
2.virtual�̳л����Ӵ�С���ٶȡ���ʼ��������ֵ�����Ӷȵȵȳɱ������virtual base classes �����κ����ݣ��������ʵ�ü�ֵ�������
3.���ؼ̳е�ȷ��������;������һ������漰 �� public  �̳�ĳ�� Interface  class"
�� �� private  �̳�ĳ��Э��ʵ�ֵ�class "  ��������ϡ�
*/