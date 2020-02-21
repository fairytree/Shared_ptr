#pragma once		
#include <iostream>		
#include <string>

template<typename T>
class Shared_ptr
{
public:
	Shared_ptr();                                   // default constructor
	Shared_ptr(T* objName);					// constructor
	Shared_ptr(const Shared_ptr& ptr1);				// copy constructor
	Shared_ptr& operator=(const Shared_ptr& rhs);	// assignment operator
	~Shared_ptr();									// destructor

	T* elem();
	size_t count();

private:
	T* _elem = nullptr;
	size_t* _count = nullptr;
};

template<typename T>
Shared_ptr<T>::Shared_ptr()
	: _elem(nullptr), _count(new size_t(0))
{
}

template<typename T>
Shared_ptr<T>::Shared_ptr(T* objName)      // constructor
{
	if (objName) {
		_elem = objName;
		_count = new size_t(1);
	}
	else {
		_elem = nullptr;
		_count = new size_t(0);
	}
}

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr& ptr1)   /* copy constructor */
{
	if (ptr1._elem) {
		_elem = ptr1._elem;
		_count = ptr1._count;
		++(*_count);
	}
	else {
		throw std::runtime_error("paramter is null");   /* "throw" caues the program to exit the "}" of main().  */
	}
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr& rhs)
{
	if (rhs._elem) {
		delete _elem;
		delete _count;
		_elem = rhs._elem;
		_count = rhs._count;
		++(*_count);
		return *this;
	}
	else {
		throw std::runtime_error("paramter is null");   /* "throw" caues the program to exit the "}" of main().  */
	}
}

template<typename T>
Shared_ptr<T>::~Shared_ptr()    /* execute upon exit of "}" */
{
	std::cout << "pointercount before shared_ptr destructor = " << *_count << std::endl;
	
	--(*_count);

	std::cout << "Shared_ptr destructor" << std::endl;

	if ((*_count) != 0) {
		std::cout << "pointercount after shared_ptr destructor = " << *_count << std::endl;
	}
	else
	{
		delete _elem;
		delete _count;
		std::cout << "pointercount after shared_ptr destructor = 0" << std::endl;
	}
}

template<typename T>
T* Shared_ptr<T>::elem()
{
	return _elem;
}

template<typename T>
size_t Shared_ptr<T>::count()
{
	return *_count;
}