//������const,enum,inline �滻#define
//����define���Ǵ�����������

#include<iostream>

#define CALL_WITH_MAX(a,b) f((a)>(b)?(a):(b))

template <typename T>
void f(T a) {
	using namespace std;
	cout <<"a��ֵΪ" << a << endl;
}

//template inline ������������#define
template <typename T>
inline void CallWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}

class GamePlayer {
private:
	static const int NumTurns = 5;//class�ڵ�ר����������ʽ��Ϊ��֤��ֻ��һ�ݣ�������Ϊstaitic
	int scores[NumTurns];

	//�ɱ����������ڲ�����static��Ա������ʽ�л�ó�ֵ����ʹ��enum�����������
	enum {NumTurns2 =6};
	int score2[NumTurns2];

};

//����Ҫȡclassר�������ĵ�ַʱ����Ҫһ������ʽ
const int GamePlayer::NumTurns;

/*
int main() {
	using namespace std;
	int a = 5, b = 0;
	//ʹ��template inline a��ֵ����������
	CallWithMax(++a, b);//a���Ӧ����6
	a=5;
	CALL_WITH_MAX(++a, ++b);//�����aֵ��Ȼ��7������Ϊdefine ����++a������Ϊ��a��,����f���൱��ִ�е��ǣ� cout <<"a��ֵΪ" << ++a << endl;
}
*/


/*
�ܽ�
1.���ڵ��������������const�����enums�滻#define
2.�������ƺ����ĺ꣬��ø���inline�����滻#defines
*/