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
class copyAbleClass{

public:
	copyAbleClass(){};
	copyAbleClass(int iTestInput){
		iTestNonConst=iTestInput;
	};

	~copyAbleClass(){};

	int getiTestNonConst(void){
		return iTestNonConst;
	};

private:
	int iTestNonConst;
};

class onlyMemberFunctionCopyClass{

public:
	onlyMemberFunctionCopyClass(int iTestInput){
		iTestNonConst=iTestInput;
	};

	~onlyMemberFunctionCopyClass(){};

	int getiTestNonConst(void){
		return iTestNonConst;
	};

	void doCopy(onlyMemberFunctionCopyClass& object1,onlyMemberFunctionCopyClass& object2){object1=object2;};

private:

	onlyMemberFunctionCopyClass(const onlyMemberFunctionCopyClass&);
	onlyMemberFunctionCopyClass& operator=(const onlyMemberFunctionCopyClass&);
	int iTestNonConst;
};


class uncopyAble{

public:
	uncopyAble(){};

	~uncopyAble(){};

private:
	uncopyAble(const uncopyAble&);
	uncopyAble& operator=(const uncopyAble&);
	
};

// ## Didn't work
//class uncopyAbleInherited:private uncopyAble{
//
//public:
//	uncopyAbleInherited(int iTestInput){
//		iTestNonConst=iTestInput;
//	};
//
//	~uncopyAbleInherited(){};
//
//	int getiTestNonConst(void){
//		return iTestNonConst;
//	};
//
//	void doCopy(uncopyAbleInherited& object1,uncopyAbleInherited& object2){object1=object2;};
//
//private:
//
//	//uncopyAbleInherited(const uncopyAbleInherited&);
//	//uncopyAbleInherited& operator=(const uncopyAbleInherited&);
//	int iTestNonConst;
//};


int main(void){

	// Allows Copy
	copyAbleClass copyClass1(1);
	copyAbleClass copyClass2(2);
	copyAbleClass copyClass3(copyClass2);
	std::cout<<"Before Copy: Object1: "<<copyClass1.getiTestNonConst()<<" - Obj2: "<<copyClass2.getiTestNonConst()<<std::endl;
	copyClass1 = copyClass2;
	std::cout<<"After Copy: Object1: "<<copyClass1.getiTestNonConst()<<" - Obj2: "<<copyClass2.getiTestNonConst()<<std::endl;
	std::cout<<"Obj3: "<<copyClass3.getiTestNonConst()<<std::endl;

	// Only allowe copy by member functions
	onlyMemberFunctionCopyClass memberCopyObject1(1);
	onlyMemberFunctionCopyClass memberCopyObject2(2);
	// ## Not allowed since copy constructpr is private
	//onlyMemberFunctionCopyClass memberCopyObject3(memberCopyObject2);
	// ## Not allowed since copy assignment operator is private
	//memberCopyObject1 = memberCopyObject2;
	std::cout<<"Before Copy: Object1: "<<memberCopyObject1.getiTestNonConst()<<" - Obj2: "<<memberCopyObject2.getiTestNonConst()<<std::endl;
	// ## Didn't work I don't no why maybe compiler is is just too clever
	//memberCopyObject1.doCopy(memberCopyObject1,memberCopyObject2);
	std::cout<<"After Copy: Object1: "<<memberCopyObject1.getiTestNonConst()<<" - Obj2: "<<memberCopyObject2.getiTestNonConst()<<std::endl;

	system("Pause");

	// ########## New ########## 
	//std::vector<copyAbleClass> Test(3,copyAbleClass());
	return 0;
}