#pragma once		
#include <iostream>		
#include <string>

template<typename T>
class Shared_ptr
{
public:
	Shared_ptr();                                   // default constructor
	explicit Shared_ptr(T* objName);			    // constructor
	Shared_ptr(const Shared_ptr& ptr1);				// copy constructor
	Shared_ptr(Shared_ptr&& ptr1);				    // move copy constructor
	Shared_ptr& operator=(const Shared_ptr& rhs);	// assignment operator
	Shared_ptr& operator=(Shared_ptr&& rhs);	    // move assignment operator
	~Shared_ptr();									// destructor

	T* elem();
	size_t count();

private:
	T* _elem = nullptr;
	size_t* _count = nullptr;
};

template<typename T>
Shared_ptr<T>::Shared_ptr()                  // default constructor
	: _elem(nullptr),
	_count(new size_t(0))
{
	std::cout << "default constructor called" << std::endl;
}

template<typename T>
Shared_ptr<T>::Shared_ptr(T* objName)      // constructor
{
	if (objName) {
		_elem = objName;
		_count = new size_t(1);
		std::cout << "constructor with size_t(1) called" << std::endl;
	}
	else {
		_elem = nullptr;
		_count = new size_t(0);
		std::cout << "constructor with size_t(0) called" << std::endl;
	}
}

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr& ptr1)   // copy constructor
	: _elem(ptr1._elem),
	_count(ptr1._count)
{
	++(*_count);
	std::cout << "copy constructor called" << std::endl;
}


template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr&& ptr1)   // move copy constructor
	: _elem(ptr1._elem),
	_count(ptr1._count)
{
	ptr1._elem = nullptr;
	ptr1._count = nullptr;
	std::cout << "move copy constructor called" << std::endl;
}


template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr& rhs)   // assignment operator
{
	std::cout << "assignment operator called" << std::endl;
	delete _elem;
	delete _count;
	_elem = rhs._elem;
	_count = rhs._count;
	++(*_count);
	return *this;
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr&& rhs)   // move assignment operator
{
	std::cout << "move assignment operator called" << std::endl;
	delete _elem;
	delete _count;
	_elem = rhs._elem;
	_count = rhs._count;
	rhs._elem = nullptr;
	rhs._count = nullptr;
	return *this;

}

template<typename T>
Shared_ptr<T>::~Shared_ptr()       // destructor
{
	if (_count == nullptr)         // ok to delete nullptr multiple times.
	{
		std::cout << "_count == nullptr. The shared_ptr has already been deleted." << std::endl;
		return;
	}

	if (*_count == 0)         // *_count == 0 when call destructor right after default constructor.  
	{
		delete _elem;
		delete _count;
		std::cout << "*_count == 0 before destructor. Shared_ptr is now deleted." << std::endl;
		return;
	}

	std::cout << "_count before destructor = " << *_count << std::endl;

	--(*_count);   // _count is unsigned, "--" will make '0' a huge number. 

	std::cout << "Shared_ptr destructor" << std::endl;

	if (*_count == 0) {
		delete _elem;
		delete _count;
		std::cout << "*_count == 0, shared_ptr is now deleted " << std::endl;
	}
	else
	{
		std::cout << "_count after destructor = " << *_count << std::endl;
	}

}

template<typename T>
T* Shared_ptr<T>::elem()      // return the pointer that points to the object
{
	return _elem;
}

template<typename T>
size_t Shared_ptr<T>::count()         // return the number of pointers that point to the same object
{
	if (_count == nullptr)
	{
		return 0;
		std::cout << "this shared_ptr has already been deleted." << std::endl;

	}
	else {
		return *_count;
	}
}