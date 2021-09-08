//��ʹ��traits classes����������Ϣ

/*
STL���溬��5�ֵ�����
1.input��������ֻ��ǰ��һ��һ����ֻ��ȡ��һ�Ρ�
2.output��������ֻ��ǰ��һ��һ����ֻͿ����һ��
3.forward��������ǰ����+�ɶ�д���
4.bidirectional��������forward+������������ƶ���
5.random_access������:������ʵ�֧�֡�

������ϵ�ǳ����׵õ���
struct intput_iterator_tag{};
struct output_iteratoe_tag{};
struct forward_iterator_tag{}:public input_iterator_tag{};
struct bidirectional_iterator_tag:forward_iterator_tag{}��
struct random_access_iterator_tag:public bidirectional_iterator_tag{}

��������ϣ��ʵ�ֵ� advance ������ʾ
template<typename IterT,typename DistT>
void advance(IterT& iter,DistT d){
	if(iter is a random access iterator) {
		iterT += d;
	}else{
		if(d >0){while(d--)++iter;}
		else{while(d++)--iter; }
		}
}
���Ͽ�֪������ϣ���ڱ����ھ�֪����ȡ���͵���Ϣ��������Traits�������ṩ��
*/

/*
Traits����Ҫ��
1.���������ͱ�����Զ�������Ч��һ�£������������������Ϊconst char* �� int,
�������޷�����ϢǶ����ԭʼָ���ڡ�
���Խ���ķ������£�
A.�����Զ������
���Զ���������
template<...>
class deque{
public:
	class iterator{
	public:
		typedef random_access_iterator_tag iterator_category;
	};
};

��iterator_traits ��
template<typename IterT>
structr iterator_traits{
		typedef typename IterT::iterator_category iterator_category;  
};
B.����������������Ҫʹ��ƫ�ػ�
template<typename IterT>
structr iterator_traits<IterT*>{
		typedef  random_access_iterator_tag iterator_category;
};

�ܰ������ź�����ע����ǰ��α�����У�
	if(iter is a random access iterator)
��λ������������й����У�ȷ���Ƿ��������û�дﵽԤ��

���Ը���ȷ������Ӧ��������ʾ


template<typename IterT, typename DistT>
void doAdvance(IterT& iter,DistT d,std::random_access_iterator_tag){
iter+=d;
}
�������ȥ

 template<typename IterT,typename DistT>
 void advance(IterT& iter,DistT d){
	doAdvance(iter.d.typename std::iterator_traits<IterT>::iterator_category());
 }

 �ܵ���˵��
 1.�������غ�������ģ�庯����doAdvance)���˴˼�Ĳ��ֻ�и��Ե�traits���� �������ʵ�֣�
 2.����һ�����ƺ�������ģ�壨advance��,�为����������ĺ�����������traits classes��Ϣ��
*/

/*
�ܽ�
1.Traits classesʹ�á����������Ϣ���ڱ��������á�������templates�͡�templates�ػ������ʵ�֡�
2.�������ؼ�����traits classses�п����ڱ����ڶ�����ִ��if...else���ԡ�
*/