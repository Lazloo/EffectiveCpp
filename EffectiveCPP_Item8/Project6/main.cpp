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

class Polymorphic {virtual void member(){}};
class classWithException{

public:
	classWithException():pb(0),iTest(0),closeBool(false){
		pb=0;
		std::cout<<"classWithException was created"<<std::endl;
	};

	~classWithException(){
		if(!closeBool){
			try{
			
				typeid(pb);
				//std::cout<<typeid(pb)<<std::endl;
				std::cout<<"Try destructor"<<std::endl;
				throw 10;
			}
			catch(...){
				std::cout<<"Exception occured"<<std::endl;
				std::system("Pause");
				std::abort();
			}
			std::cout<<"classWithException was destroyed"<<std::endl;
		}
	};

	void close(){
		if(!closeBool){
			try{
				std::cout<<"Call Close"<<std::endl;
				closeBool=true;
			}
			catch(...){

			}
		}
	};
private:
	Polymorphic * pb;
	bool closeBool;
	int iTest;
};
int main(void){
	classWithException* exceptionObject = new classWithException;

	delete exceptionObject;
	system("Pause");
	return 0;
}