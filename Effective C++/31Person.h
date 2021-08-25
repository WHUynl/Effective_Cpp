#pragma once
#include<iostream>
using namespace std;

class Person{
public:
	virtual ~Person() {}
	virtual string name() const = 0;
	static shared_ptr<Person> createPerson(const string& name);
};