// Include standard headers
#define GLM_FORCE_RADIANS
////Memory Leak
#include <stdlib.h>
//#include "vld.h"
//#define _DEBUG

#include <fstream>
#include <iostream>

#include <vector>
#include <stdio.h>
#define TESTVAR 1.63
using namespace std;

const float testVar = static_cast<float>(1.63);

class classA{
public:
	classA(){
		std::cout<<"A works. i is: "<<std::endl;
	};
	~classA(){};
};


class classB{
public:
	explicit classB(int i=0){
		std::cout<<"B works. i is: "<<i<<std::endl;
	};
	~classB(){};
};



class classC{

public:
	classC(int i){
		std::cout<<"C works. i is: "<<i<<std::endl;
		count++;
		std::cout<<"Count is: "<<count<<" NumTurns: "<<NumTurns<<std::endl;
		std::cout<<"NumTurns-Adress: "<<&NumTurns<<std::endl;
		//NumTurns = 1;
	};
	~classC(){};


	static const int NumTurns = -1;
private:
	static std::size_t count;
	//static int count;
};
std::size_t classC::count = 0;

class classCopy{
public:
	classCopy(int i){
		testVar = i;
		std::cout<<"classCopy works. i is: "<<i<<std::endl;
	};
	classCopy(const classCopy& object){
		//testV
		testVar = object.testVar;
		std::cout<<"Copy constructor, i: "<<testVar<<std::endl;
	};

	classCopy& operator=(const classCopy& object){
		//testVar = -4;
		if(this!=&object){
			testVar = object.testVar;
			std::cout<<"Copy assignment operator, i: "<<object.testVar<<std::endl;
		}
		else{
			std::cout<<"No copy assigment used since identical object, i: "<<object.testVar<<std::endl;
		}

		// By Convenction always return this
		return (*this);
	};

	int testVar;
	~classCopy(){};
};

void doSomethingA(classA A){std::cout<<"Function A works"<<std::endl;};
void doSomethingB(classB B){std::cout<<"Function B works"<<std::endl;};
void doSomethingC(classC C){std::cout<<"Function C works"<<std::endl;};

//using namespace std;
int main(void){
	classA testA;
	classB testB1;
	classB testB2(5);
	
	// Does work but no error
	std::cout << std::endl << "----- Class C without Input -----" << std::endl;
	classC testC();
	
	// Does not work since testC was not correct initialized
	//doSomethingC(testC);


	// Explicite conversion
	std::cout << "----- Explicite conversion -----" << std::endl;
	doSomethingC(classC(1));

	// Implicite conversion: Constructor of class C is automatically activated
	std::cout << "----- Implicite conversion -----" << std::endl;
	doSomethingC(1);

	// Implicite conversion: Constructor of class B is not automatically activated
	//doSomethingB(1);


	std::cout << std::endl << "--------------- classCopy ---------------" << std::endl;
	std::cout << "Create Objects (Obj1=1,Obj2=2)" << std::endl;
	classCopy testClassCopy1(1);
	classCopy testClassCopy2(2);

	// Copy assignment operator
	std::cout<<"### Copy assignment operator Obj2=Obj2 & Obj1 = Obj2"<<std::endl;
	testClassCopy2 = testClassCopy2;
	testClassCopy1 = testClassCopy2;
	std::cout<<"After copy testVar1: "<<testClassCopy1.testVar<<std::endl;
	std::cout<<"After copy testVar2: "<<testClassCopy2.testVar<<std::endl;

	
	// Copy constructor
	std::cout<<"### Copy constructor"<<std::endl;
	classCopy testClassCopy3(testClassCopy2);
	classCopy testClassCopy4=testClassCopy1;

	// --- error C2106: '=' : left operand must be l-value
	//TESTVAR = 0.1;
	// --- error C3892: 'testVar' : you cannot assign to a variable that is const
	//testVar = 0.1;

	std::cout << std::endl << "----- Just Counting -----" << std::endl;
	classC testC3(1);
	classC testC4(1);
	classC testC5(1);
	//std::cout << (&(const int classC::NumTurns)) << std::endl;
	//std::cout << &(const int classC::NumTurns) << std::endl;
	system("Pause");
}