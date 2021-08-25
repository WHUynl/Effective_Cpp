#pragma once
#include"31Person.h"
#include"31RealPerson.h"

shared_ptr<Person> Person::createPerson(const string& name) {
	return shared_ptr<Person>(new RealPerson(name));
}