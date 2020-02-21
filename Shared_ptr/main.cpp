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

	Shared_ptr<myClass> ptr4(std::move(ptr1));
	std::cout << "printing ptr4: " << ptr4.elem()->name() << "; ptr4._count = " << ptr4.count() << std::endl;

	Shared_ptr<myClass> ptr5;
	ptr5 = std::move(ptr2);
	std::cout << "printing ptr5: " << ptr5.elem()->name() << "; ptr5._count = " << ptr5.count() << std::endl;

	return 0;
}

