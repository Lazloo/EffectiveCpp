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

class testDerivedFromInterface :private testInterface&private testInterface2{
public:
	testDerivedFromInterface(){};
	~testDerivedFromInterface(){};

private:
	virtual void virtualFct1(void){ std::cout << "virtualFct1" << std::endl; };
	virtual void virtualFct2(void){ std::cout << "virtualFct2" << std::endl; };
};

class testDerivedClass:private testBaseClass{
public: 
	testDerivedClass(){virtualFct();};
	~testDerivedClass(){};
	
private:
	//virtual void virtualFct(){};
	virtual void virtualFct(){std::cout<<"Call virual function"<<std::endl;};
};

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

int main(void){
	// testDerivedClass is dervied from an abract function (contains one virtual function)
	// Virtual function is completed and called in the constructor of testDerivedClass
	testDerivedClass testObject;
	// Standard derived class. No virtual function exist in basis class
	testDerivedClass2 testObject2(13);
	system("Pause");
	return 0;
}