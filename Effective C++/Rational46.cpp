#include"Rational46.hpp"
#include<iostream>
int main() {
	RationalReal<int> oneHalf(1, 2);//รปฮสฬโ
	RationalReal<int> answer = oneHalf * 2;
	std::cout << answer.num();
}