#pragma once		
#include <iostream>		
#include <string>

template<typename T>
class Shared_ptr
{
public:
	Shared_ptr();                                   // default constructor
	Shared_ptr(T* objName);					        // constructor
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
Shared_ptr<T>::Shared_ptr(const Shared_ptr& ptr1)   // copy constructor
{
		_elem = ptr1._elem;
		_count = ptr1._count;
		++(*_count);
}

template<typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr&& ptr1)   // move copy constructor
{
		_elem = ptr1._elem;
		_count = ptr1._count;
		ptr1._elem = nullptr;
		ptr1._count = nullptr;
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr& rhs)   // assignment operator
{
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
	delete _elem;
	delete _count;
	_elem = rhs._elem;
	_count = rhs._count;
	rhs._elem = nullptr;
	rhs._count = nullptr;
	return *this;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr()       // desctructor
{
	if (_count == nullptr)
	{
		std::cout << "This pointer has been moved." << std::endl;
		return;
	}
	else
	{
		std::cout << "pointercount before shared_ptr destructor = " << *_count << std::endl;
		
		--(*_count);
		
		std::cout << "Shared_ptr destructor" << std::endl;

		if ((*_count) == 0) {
			delete _elem;
			delete _count;
			std::cout << "pointercount after shared_ptr destructor = 0" << std::endl;
		}
		else
		{
			std::cout << "pointercount after shared_ptr destructor = " << *_count << std::endl;
		}
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
	if (_count == nullptr)
	{
		return 0;
		std::cout << "this pointer is destroyed" << std::endl;

	}
	else {
		return *_count;
	}
}