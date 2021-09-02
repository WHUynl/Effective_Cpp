//通过复合塑模出has-a或“根据某物实现出”
#include<list>
using namespace std;

//将list应用于Set的正确做法。也是is-implemented-in-terms-of （根据某物实现出）的表现
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
总结：
1.复合(composition )的意义和public继承完全不同。
2.在应用域 (application domain )，复合意味has-a（有一个）。在实现域(implementation domain)，
复合意味 is-implemented-in-terms-of （根据某物实现出）。

*/