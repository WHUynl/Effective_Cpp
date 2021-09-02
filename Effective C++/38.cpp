//ͨ��������ģ��has-a�򡰸���ĳ��ʵ�ֳ���
#include<list>
using namespace std;

//��listӦ����Set����ȷ������Ҳ��is-implemented-in-terms-of ������ĳ��ʵ�ֳ����ı���
template<class T>	
class Set {
public:
	bool member(const  T& item)  const; 
	void remove(const T& item); 
	void insert(const T& item);
	std::size_t size() const;
private:
	std::list<T>rep;
};

template<typename  T>
bool  Set<T>::member(const  T& item)   const {
	return  std::find(rep.begin(), rep.end(), item) != rep.end();
}
template<typename  T>
void  Set<T>::insert(const  T& item) {
	if (!member(item))   rep.push_back(item);
}
template <typename T>
void Set<T>::remove(const T& item) {
	typename list<T>::iterator it =
		std::find(rep.begin(), rep.end(), item);
	if (it != rep.end())  rep.erase(it);
	
}

template<typename T>
size_t Set<T>::size()  const {
	return rep.size();
}
/*
�ܽ᣺
1.����(composition )�������public�̳���ȫ��ͬ��
2.��Ӧ���� (application domain )��������ζhas-a����һ��������ʵ����(implementation domain)��
������ζ is-implemented-in-terms-of ������ĳ��ʵ�ֳ�����

*/