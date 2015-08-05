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
	classA():iTestConst(3){
		iTestNonconst = 1;
		//const int classA::iTestConst;
		//const_cast<int&>(iTestConst) = 3;
		//iTestConst = 2;
		std::cout<<"iTestConstConst: "<<iTestConst<<std::endl;
		//std::cout<<"iArrayConst: "<<iArrayConst[0]<<"\t"<<iArrayConst[1]<<"\t"<<iArrayConst[2]<<std::endl;
		std::cout<<"Class A defined"<<std::endl;
	};

	~classA(){};

	void testFunction1(void){std::cout<<"Function for non constant objects"<<std::endl;};
	void testFunction1(void) const {std::cout<<"Function for constant objects"<<std::endl;};

	void testFunction2(const std::vector<int>& iTestVec){
		std::cout<<"Function2 for non constant objects. iTest is: "<<iTestVec[0]<<std::endl;
	};
	void testFunction2(const std::vector<int>& iTestVec) const {
		std::cout<<"Function2 for constant objects. iTest is: "<<iTestVec[0]<<std::endl;
	};

	int operator[](std::size_t position){
		std::cout<<"iTestNonconst: "<<iTestNonconst<<std::endl;
		//int iNew = 
		const int iNew = (static_cast<const classA&>(*this))[1];
		int iNew2 = const_cast<int&>(iNew);
		iNew2++;
		std::cout<<"iNew: "<<iNew<<std::endl;
		std::cout<<"iNew++: "<<iNew2<<std::endl;
		//std::cout<<"iTestNonconst: "<<iTestNonconst<<std::endl;
		return iTestNonconst;
	};

	const int operator[](std::size_t position) const{
		return iTestConst;
	};
	
private:
	const int iTestConst;
	int iTestNonconst;
	//const int iArrayConst[3];
};

class TextBlock {
public:
	TextBlock(){
		text="Text";
		TestIntegerNonMutable = 11;
		TestIntegerMutable = 22;
	};
	~TextBlock(){};
	const char& operator[](std::size_t position) const // operator[] for
		{ return text[position]; } // const objects
	char& operator[](std::size_t position)   // operator[] for
		{ return text[position]; } // non-const objects
	const int& getIntegerReference(void) const {return TestIntegerNonMutable;};
	int& getIntegerReferenceMutable(void) const {return TestIntegerMutable;};
	int& getIntegerReferenceMutableNonConst(void) {return TestIntegerMutable;};
	//const char& getCharReference(void) const {return text[0];};
	private:
		std::string text;
		int TestIntegerNonMutable;
		mutable int TestIntegerMutable;
		//char * text2;
};
//using namespace std;
int main(void){
	char *greeting1 = "Hallo World";
	char *greeting2 = "Hallo World 2";
	
	char * pointer1 = greeting1;
	const char * pointer2 = greeting2;
	// I don't understand the effect of const here
	
	//greeting1 = "Test";
	greeting2 = "TestTest";
	//greeting2[0] = 'X';
	
	//pointer2 = "Test";
	std::cout<<"greeting1: "<<greeting1<<std::endl;
	std::cout<<"greeting2: "<<greeting2<<std::endl;
	std::cout<<"Pointer1: "<<pointer1<<std::endl;
	std::cout<<"Pointer2: "<<pointer2<<std::endl;
	pointer1 = greeting2;
	std::cout<<"Pointer1 after change: "<<pointer1<<std::endl;

	int iTest = 1;
	int iTest2 = 30;
	const int * pointer3 = &iTest;

	std::cout<<"Pointer3: "<<*pointer3<<std::endl;
	iTest = 10;
	std::cout<<"Pointer3 after change: "<<*pointer3<<std::endl;
	// Coes not work if "const int * pointer3 = &iTest;"
	//*pointer3 = 20;
	std::cout<<"Pointer3 after change 2: "<<*pointer3<<std::endl;
	pointer3 = &iTest2;
	std::cout<<"Pointer3 after change 3: "<<*pointer3<<std::endl;


	// STL iterators are modeled on pointers
	std::vector<int> vec(20);

	
	std::vector<int>::iterator iter = // iter acts like a T* const
	vec.begin();
	*(iter) = 10; // OK, changes what iter points to
	//++iter; // error! iter is const

	std::vector<int>::const_iterator cIter = // cIter acts like a const T*
	vec.begin();
	//*cIter = 10; // error! *cIter is const
	++cIter; // fine, changes cIter
	//cIter = 20;

	class classA testObjectA1;
	const classA testObjectA2;
	std::vector<int> iTestVec(3);
	iTestVec[0]=10;
	testObjectA1.testFunction1();
	testObjectA2.testFunction1();
	testObjectA1.testFunction2(iTestVec);
	testObjectA2.testFunction2(iTestVec);

	std::string text1 = "Great";
	std::cout<<text1[0]<<std::endl;
	//(text1[0]) = "a";
	//std::cout<<text1[0]<<std::endl;
	//iTest*iTest2 = iTest;

	TextBlock textBlockObject;
	std::cout<<"textBlockObject[0]:"<<textBlockObject[0]<<std::endl;
	textBlockObject[0]= 'X';
	std::cout<<"textBlockObject[0] After Change:"<<textBlockObject[0]<<std::endl;

	std::string greeting4 = "TT";
	std::cout<<"greeting4: "<<greeting4<<std::endl;
	greeting4[0] = 'X';
	std::cout<<"greeting4 After Change: "<<greeting4<<std::endl;

	char greeting5[] = "TT";
	std::cout<<"greeting5: "<<greeting5<<std::endl;
	greeting5[0] = 'X';
	std::cout<<"greeting4 After Change: "<<greeting5<<std::endl;


	int pInt = textBlockObject.getIntegerReference();
	std::cout<<"textBlockObject.getIntegerReference():"<<textBlockObject.getIntegerReference()<<"\tpInt: "<<pInt<<std::endl;
	pInt++;
	std::cout<<"pInt After ++: "<<pInt<<std::endl;
	std::cout<<"textBlockObject.getIntegerReference(): "<<textBlockObject.getIntegerReference()<<std::endl;
	std::cout<<"textBlockObject.getIntegerReferenceMutable(): "<<textBlockObject.getIntegerReferenceMutable()<<std::endl;

	const TextBlock textBlockObject2;
	std::cout<<"textBlockObject2.getIntegerReferenceMutable(): "<<textBlockObject2.getIntegerReferenceMutable()<<std::endl;
	//std::cout<<"textBlockObject2.getIntegerReferenceMutableNonConst(): "<<textBlockObject2.getIntegerReferenceMutableNonConst()<<std::endl;

	const int  iTestTest = 1;
	int iTestTestTest=1;
	const_cast<int&>(iTestTest);
	//dynamic_cast<int>(iTestTestTest);
	static_cast<const int&>(iTestTest);
	dynamic_cast<const TextBlock&>(textBlockObject2);

	class classA testObjectA3;
	testObjectA3[1];
	system("Pause");
}