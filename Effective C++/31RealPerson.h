#pragma once
#include"31Person.h"

class RealPerson :public Person{
public:
	RealPerson(const string& name) :theName(name) {}
	virtual string name() const;
private:
	string theName;
};