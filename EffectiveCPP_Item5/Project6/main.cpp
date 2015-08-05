// Include standard headers
#define GLM_FORCE_RADIANS
////Memory Leak
#include <stdlib.h>
#include "vld.h"
//#define _DEBUG

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
class classA{

public:
	classA(int iTestInput):iTestConst(3){
		std::cout<<"iTestInput: "<<iTestInput<<std::endl;
	};

	~classA(){};

	int getTestConst(void){return iTestConst;};
	void setTestNonConst(int testNonConst){iTestNonConst=testNonConst;};
	int getTestNonConst(void){return iTestNonConst;};
private:
	const int iTestConst;
	int iTestNonConst;
};

class classB{

public:
	//int getTestConst(void){return iTestConst;};
	void setTestNonConst(int testNonConst){iTestNonConst=testNonConst;};
	int getTestNonConst(void){return iTestNonConst;};
private:
	//const int iTestConst;
	int iTestNonConst;
};
 
class classC:public classB{

public:
	//int getTestConst(void){return iTestConst;};
	//void setTestNonConst(int testNonConst){iTestNonConst=testNonConst;};
	//int getTestNonConst(void){return iTestNonConst;};
private:
	//const int iTestConst;
	//int iTestNonConst;
};

// Private Copy Assignement
class classD{

public:
	//int getTestConst(void){return iTestConst;};
	void setTestNonConst(int testNonConst){iTestNonConst=testNonConst;};
	int getTestNonConst(void){return iTestNonConst;};
private:
	classD& operator=(const classD& object){
		//testVar = -4;
		if(this!=&object){
			iTestNonConst = object.iTestNonConst;
			std::cout<<"Copy assignment operator, i: "<<object.iTestNonConst<<std::endl;
		}
		else{
			std::cout<<"No copy assigment used since identical object, i: "<<object.iTestNonConst<<std::endl;
		}

		// By Convenction always return this
		return (*this);
	};

	//const int iTestConst;
	int iTestNonConst;
};

class classE:public classD{

public:
	//int getTestConst(void){return iTestConst;};
	//void setTestNonConst(int testNonConst){iTestNonConst=testNonConst;};
	//int getTestNonConst(void){return iTestNonConst;};
private:
	//const int iTestConst;
	//int iTestNonConst;
};

int main(void){
	// First Object
	classA testClassA1(1);
	testClassA1.setTestNonConst(12);
	std::cout<<"iTestConst 1: "<<testClassA1.getTestConst()<<std::endl;
	std::cout<<"iTestNonConst 1: "<<testClassA1.getTestNonConst()<<std::endl;

	// Object that does not work since no default construtor defined
	classA testClassA2();
	//std::cout<<"iTestConst 2: "<<testClassA2.getTestConst()<<std::endl;

	// Copy Constructor
	classA testClassA3(testClassA1);
	std::cout<<"iTestNonConst A3: "<<testClassA3.getTestNonConst()<<std::endl;
	testClassA1.setTestNonConst(-12);
	std::cout<<"After Change: iTestNonConst A3: "<<testClassA3.getTestNonConst()<<"\tiTestNonConst A1: "<<testClassA1.getTestNonConst()<<std::endl;
	
	// Copy Assignment not possible since one member variable is const
	classA testClassA4(1);
	testClassA4.setTestNonConst(-1);
	std::cout<<"iTestNonConst A4: "<<testClassA4.getTestNonConst()<<std::endl;
	//testClassA4 = testClassA3;
	//std::cout<<"iTestNonConst A4 after copy: "<<testClassA4.getTestNonConst()<<std::endl;



	classB testClassB1;
	classB testClassB2;
	testClassB1.setTestNonConst(11);
	testClassB2.setTestNonConst(-11);
	//testClassB.
	// Copy Assignement
	std::cout<<"iTestNonConst B1: "<<testClassB1.getTestNonConst()<<std::endl;
	std::cout<<"iTestNonConst B2: "<<testClassB2.getTestNonConst()<<std::endl;
	testClassB1 = testClassB2;
	std::cout<<"After copy - iTestNonConst B1: "<<testClassB1.getTestNonConst()<<"\tiTestNonConst B2: "<<testClassB2.getTestNonConst()<<std::endl;
	testClassB1.setTestNonConst(10);
	testClassB2.setTestNonConst(-10);
	std::cout<<"After Change - iTestNonConst B1: "<<testClassB1.getTestNonConst()<<"\tiTestNonConst B2: "<<testClassB2.getTestNonConst()<<std::endl;


	// Derived class
	classC testClassC1;
	classC testClassC2;
	classC testClassE1;
	classC testClassE2;
	testClassC1.setTestNonConst(22);
	testClassC2.setTestNonConst(-22);
	testClassE1.setTestNonConst(33);
	testClassE2.setTestNonConst(-33);

	std::cout<<"iTestNonConst C1: "<<testClassC1.getTestNonConst()<<std::endl;
	std::cout<<"iTestNonConst C2: "<<testClassC2.getTestNonConst()<<std::endl;
	std::cout<<"iTestNonConst E1: "<<testClassE1.getTestNonConst()<<std::endl;
	std::cout<<"iTestNonConst E2: "<<testClassE2.getTestNonConst()<<std::endl;
	testClassC1 = testClassC2;
	std::cout<<"After copy - iTestNonConst C1: "<<testClassC1.getTestNonConst()<<"\tiTestNonConst C2: "<<testClassC2.getTestNonConst()<<std::endl;
	testClassE1 = testClassE2;
	std::cout<<"After copy - iTestNonConst E1: "<<testClassE1.getTestNonConst()<<"\tiTestNonConst E2: "<<testClassE2.getTestNonConst()<<std::endl;

	classD testD1;
	classD testD2;
	// Not possible since private copy assignement operator
	testD1 = testD2;
	system("Pause");
	return 0;
}