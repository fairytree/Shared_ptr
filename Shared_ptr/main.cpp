#include "Shared_ptr.h"	
#include "myClass.h"	
#include <string.h>

int main()
{
	Shared_ptr<myClass> ptr1(new myClass("Hello,Shu"));

	std::cout << "printing ptr1: " << ptr1.elem()->name() << "; ptr1._count = " << ptr1.count() << std::endl;  

	Shared_ptr<myClass> ptr2(ptr1);
	std::cout << "printing ptr2: " << ptr2.elem()->name() << "; ptr2._count = " << ptr2.count() << std::endl;
	
	Shared_ptr<myClass> ptr3;
	ptr3 = ptr1;
	std::cout << "printing ptr3: " << ptr3.elem()->name() << "; ptr3._count = " << ptr3.count() << std::endl;

	return 0;
}

