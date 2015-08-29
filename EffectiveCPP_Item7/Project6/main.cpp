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
class baseClassNotVirtual{

public:
	baseClassNotVirtual(){
		std::cout<<"baseClassNotVirtual was created"<<std::endl;
	};

	~baseClassNotVirtual(){
		std::cout<<"baseClassNotVirtual was destroyed"<<std::endl;
	};

private:
};

class derivedClassNotVirtual:public baseClassNotVirtual{

public:
	derivedClassNotVirtual(){
		std::cout<<"derivedClassNotVirtual was created"<<std::endl;
	};

	~derivedClassNotVirtual(){
		std::cout<<"derivedClassNotVirtual was destroyed"<<std::endl;
	};

private:
	int iTest;
};

class baseClassVirtual{

public:
	baseClassVirtual(){
		std::cout<<"baseClassVirtual was created"<<std::endl;
	};

	virtual ~baseClassVirtual(){
		std::cout<<"baseClassVirtual was destroyed"<<std::endl;
	};

private:
};

class derivedClassVirtual:public baseClassVirtual{

public:
	derivedClassVirtual(){
		std::cout<<"derivedClassVirtual was created"<<std::endl;
	};

	//~baseClassVirtual(){std::cout<<"derivedClassVirtual was destroyed"<<std::endl;}
	~derivedClassVirtual(){
		std::cout<<"derivedClassVirtual was destroyed"<<std::endl;
	};

private:
	int iTest;
};

class AWOV { // AWOV = “Abstract w/o Virtuals”
public:
virtual ~AWOV() = 0; // declare pure virtual destructor
};

class AWOV2 :public AWOV { // AWOV = “Abstract w/o Virtuals”
//class AWOV2 { // AWOV = “Abstract w/o Virtuals”
public:
	//~AWOV2(){}; // declare pure virtual destructor
};

int main(void){
	// No Memory Leak since references 
	std::cout << "Create References" << std::endl;
	class baseClassNotVirtual baseObject1;
	class derivedClassNotVirtual derivedObject1;
	std::cout << std::endl;

	// No memory leak since pointer are not created by operator new. Constructor is not called
	std::cout<<"Create Pointer" << std::endl;
	baseClassNotVirtual* baseObjectPtr1;
	class derivedClassNotVirtual* derivedObjectPtr1;
	std::cout << std::endl;

	// No Memory Leak since ptr is deleted
	baseClassNotVirtual* baseObjectPtr2 = new baseClassNotVirtual;
	// No Memory Leak if derivedObjectPtr2 is deleted and not baseObjectPtr2_1
	derivedClassNotVirtual* derivedObjectPtr2 = new derivedClassNotVirtual;
	baseClassNotVirtual* baseObjectPtr2_1 = derivedObjectPtr2;

	// !!! Memory Leak since only base destructor is called iTest is not destroyed.
	// However this is not detected by current Memory Leak Detector
	derivedClassNotVirtual* derivedObjectPtr3 = new derivedClassNotVirtual;
	baseClassNotVirtual* baseObjectPtr3_1 = derivedObjectPtr3;
	// No Memory Leak since baseClassVirtual has virtual destructor
	derivedClassVirtual* derivedObjectPtr4 = new derivedClassVirtual;
	baseClassVirtual* baseObjectPtr41 = derivedObjectPtr4;

	// You can only declare and define AWOV2 object which class is derived from AWOV
	// AWOV is abstract and cannot be used for the declaration and definition of Objects
	//AWOV abstactObject;
	//AWOV2 nonAbstactObject;

	//baseObjectPtr3 = derivedObjectPtr2;

	// Deleting only baseObjectPtr2 is not enough. If delete derivedObjectPtr2 is not done -> Memory Leak
	delete baseObjectPtr2;
	//delete derivedObjectPtr2;

	// Only Base Destructor is called
	delete baseObjectPtr3_1;
	//delete derivedObjectPtr3;
	// Both Base Derived Destructor are called
	delete baseObjectPtr41;



	system("Pause");
	return 0;
}