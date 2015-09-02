// Include standard headers
#define GLM_FORCE_RADIANS
////Memory Leak
#include <stdlib.h>
//#include "vld.h"
//#define _DEBUG

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>

class testBaseClass{
public: 
	testBaseClass(){};
	~testBaseClass(){};
	
	void testFunction(void){
		std::cout<<"Function 1"<<std::endl;
		int *ptr = new int;
	};

	void testFunction2(void){
		// Auto Pointer: RAII - Object which calls destructor and avoids memory leak
		std::cout<<"Function 2"<<std::endl;
		std::auto_ptr<int> ptr1(new int);
		std::auto_ptr<int> ptr2(new int);
		*ptr1 = 1;
		*ptr2 = 2;
		std::cout<<"ptr1: "<<(*ptr1)<<std::endl;
		std::cout<<"ptr2: "<<*ptr2<<std::endl;
		// Copy Auto pointer ptr2 get Null pointer
		ptr1 = ptr2;
		std::cout<<"ptr1: "<<*ptr1<<std::endl;
		// Points to nothing (NUll Pointer)
		//std::cout<<"ptr2: "<<*ptr2<<std::endl;
	};

	void testFunction3(void){
		// Shared Pointer: RCSP - Object which calls destructor and avoid memory leak
		std::cout<<"Function 3"<<std::endl;
		std::shared_ptr<int> ptr1(new int);
		std::shared_ptr<int> ptr2(new int);
		*ptr1 = 1;
		*ptr2 = 2;
		std::cout<<"ptr1: "<<(*ptr1)<<std::endl;
		std::cout<<"ptr2: "<<*ptr2<<std::endl;
		// Copy Auto pointer ptr2 get Null pointer
		// An  RCSP  is  a  smart  pointer  that  keeps  track  of  how  many  objects
		// point to a particular resource and automatically deletes the resource
		// when nobody is pointing to it any longer.
		ptr1 = ptr2;
		std::cout<<"ptr1: "<<*ptr1<<std::endl;
		// Points to nothing (NUll Pointer)
		std::cout<<"ptr2: "<<*ptr2<<std::endl;
	};

	void testFunction4(void){
		std::cout<<"Function 4"<<std::endl;
		// NO ARRAY ALLOCATIONS!!!!
		// That’s  because  vector  and  string  can  almost  always  replace
		// dynamically allocated arrays.
		std::shared_ptr<int> ptr1(new int[10]);

		std::cout<<"NO ARRAY ALLOCATIONS!!!!"<<std::endl;
	};
private:
};

int main(void){
	testBaseClass testObject;
	// Memory Leak
	//testObject.testFunction();
	// Auto Pointer
	testObject.testFunction2();
	// Shared Pointer
	testObject.testFunction3();
	// Shared Pointer with array
	testObject.testFunction4();

	system("Pause");
	return 0;
}