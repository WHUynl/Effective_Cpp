//����pass-by-reference-to-const�滻pass-by-value
#include<iostream>
using namespace std;

class Window {
public:
	Window(string n):windowName(n){}
	string name() const;//���ش���
	virtual void display() const;//��ʾ���ں�����
private:
	string windowName;
};

string Window::name() const {
	return windowName;
}

void Window::display() const{
	cout << "���ǻ����display" << endl;
}

class WindowWithScrollBars :public Window {
public:
	WindowWithScrollBars(string n) :Window(n) {}
	virtual void display() const;
};

void WindowWithScrollBars::display() const {
	cout << "�����������display" << endl;
}

//������ʹ�ô�ֵ��ʽʱ����ô���������
void printNameAndDisplay(Window w) {
	cout << w.name() << endl;
	w.display();
}

//��ַ�����ƣ�1.���ٸ�����������ٴ����Ŀ��� 2.virtual����ʹ��
void printNameAndDisplayRef(const Window& w) {
	cout << w.name() << endl;
	w.display();
}

/*
int main() {
	//����derived classȴ�޷�����display,��Ϊ���ǵ�ַ�ʲ��ܵ���virtual
	WindowWithScrollBars w1("derived");
	printNameAndDisplay(w1);
	//��ַ����Ե���virtual
	printNameAndDisplayRef(w1);
}
*/

/*
1.������ pass-by-reference-to-const �滻 pass-by-value��ǰ��ͨ���Ƚϸ�Ч�����ɱ����и����� ( slicing problem) ��
2.���Ϲ��򲢲��������������ͣ��Լ�STL�ĵ������ͺ������󡣶����Ƕ��ԣ�pass-by-value�����Ƚ��ʵ���
*/