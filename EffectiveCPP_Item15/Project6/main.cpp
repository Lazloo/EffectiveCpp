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



// This Function allows only epxlicite conversion (.get())
class intClass
{
public:
	explicit intClass(int intNumber){
		*integerPointer = intNumber;
	};

	~intClass(){
		delete integerPointer;
	};

	int* get(){ return integerPointer; };

private:
	int *integerPointer = new int;
};

// This Function allows only implicite conversion (if asked for pointer than give the pointer)
class intClassImplicite
{
public:
	explicit intClassImplicite(int intNumber){
		*integerPointer = intNumber;
	};

	~intClassImplicite(){
		delete integerPointer;
	};

	// If it is asked for an iterpointer than give the member pointer
	operator int*() const{ return integerPointer; }

private:
	int *integerPointer = new int;
};

void printInteger(int* intPointer){
	std::cout << "Integer is " << *intPointer << std::endl;
};

int main(void){

	intClass intExpliciteObj(42);
	intClassImplicite intImpliciteObj(13);

	// Try direct input 
	//printInteger(intExpliciteObj);
	
	// Explicit Conversion
	printInteger(intExpliciteObj.get());

	// Implicite Conversion
	printInteger(intImpliciteObj);

	system("Pause");
	return 0;
}