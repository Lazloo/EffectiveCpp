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


// ##################### Derive Abstract Class
class testBaseClass{
public:
	//# Does not work since virtual function is not yet defined
	//testBaseClass(){virtualFct();};
	//# Will lead to an runtime error
	//testBaseClass(){testFunction();};
	testBaseClass(){};
	~testBaseClass(){};

private:
	void testFunction(){ virtualFct(); };
	virtual void virtualFct(void) = 0;
};

class testDerivedClass :private testBaseClass{
public:
	testDerivedClass(){ virtualFct(); };
	~testDerivedClass(){};

private:
	//virtual void virtualFct(){};
	virtual void virtualFct(){ std::cout << "Call virtual function" << std::endl; };
};
// #####################

// ##################### Multiple Inheritance fom interfaces
class testInterface{
public:
	testInterface(){};
	~testInterface(){};

private:
	virtual void virtualFct1(void) = 0;
};

class testInterface2{
public:
	testInterface2(){};
	~testInterface2(){};

private:
	virtual void virtualFct2(void) = 0;
};

class testDerivedFromInterface :private testInterface,private testInterface2{
public:
	testDerivedFromInterface(){};
	~testDerivedFromInterface(){};

private:
	virtual void virtualFct1(void){ std::cout << "virtualFct1" << std::endl; };
	virtual void virtualFct2(void){ std::cout << "virtualFct2" << std::endl; };
};
// #####################

// ##################### Base Class needs an input for the constructor
class testBaseClass2{
public: 
	testBaseClass2(int inputInt){virtualFctReplacement(inputInt);};
	~testBaseClass2(){};
	
private:
	//void testFunction(){virtualFctReplacement();};
	void virtualFctReplacement(int iTest){std::cout<<"iTest is: "<<iTest<<std::endl;};
};
class testDerivedClass2:public testBaseClass2{
public: 
	// Call base constructor with defined properties
	// Better than defining virtual function even some flexibility is lost
	testDerivedClass2(int input):testBaseClass2(input){
		std::cout<<"Derived Object is created"<<std::endl;
	};

	~testDerivedClass2(){};
	
private:
};
// ##################### 

// ############################## Multiple Inheritance fom interfaces, each constructor does something
class interfaceClass1
{
public:
	interfaceClass1(){ std::cout << "Interface 1" << std::endl; };
	~interfaceClass1(){};

	virtual void virtualFct1(void) = 0;
private:
	
};

class interfaceClass2
{
public:
	interfaceClass2(){ std::cout << "Interface 2" << std::endl; };	
	~interfaceClass2(){};

	virtual void virtualFct2(void) = 0;
private:
	
};

class abstractCalss
{
public:
	abstractCalss(){ std::cout << "Interface 2" << std::endl; };	
	~abstractCalss(){};

	virtual void virtualFct3(void) = 0;
private:
	
	void realFct3(void){ std::cout << "Real Function"<<std::endl; };
};

// Multiple Inherince from an abstract object(not only virtual function) does not work!
//class classDerivedFromInterfaces : public interfaceClass1, public interfaceClass2, public abstractCalss
class classDerivedFromInterfaces : public interfaceClass1, public interfaceClass2
{
public:
	classDerivedFromInterfaces(){ std::cout << "Class Multiple Inherince" << std::endl; };
	~classDerivedFromInterfaces(){};

	virtual void virtualFct1(void){ std::cout << "virtualFct_1" << std::endl; };
	virtual void virtualFct2(void){ std::cout << "virtualFct_2" << std::endl; };
private:
	
};
// ##############################

int main(void){
	// testDerivedClass is dervied from an abract function (contains one virtual function)
	// Virtual function is completed and called in the constructor of testDerivedClass
	testDerivedClass testObject;
	// Standard derived class. No virtual function exist in basis class.
	// Base Class needs an input for the constructor
	testDerivedClass2 testObject2(13);

	std::cout << std::endl;
	std::cout << "----Multiple Inherince----" << std::endl;
	classDerivedFromInterfaces testObjectMultipleinherince;
	testObjectMultipleinherince.virtualFct1();
	testObjectMultipleinherince.virtualFct2();

	system("Pause");
	return 0;
}