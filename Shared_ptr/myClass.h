#pragma once
#include <iostream>		
#include <string>

class myClass
{
public:
	myClass();
	myClass(std::string name);
	myClass(const myClass& name);
	~myClass();
	std::string& name();

private:
	std::string _name;
};

myClass::myClass()
{
	std::cout << "A nameless obj is created" << std::endl;
}

myClass::myClass(std::string name)
	: _name(name)
{
	std::cout << _name << " is created" << std::endl;
}

myClass::myClass(const myClass& name)
{
	std::cout << "myClass is copied" << std::endl;
}

myClass::~myClass()
{
	std::cout << _name << " is destroyed" << std::endl;
}

std::string& myClass::name()
{
	return _name;
}