// Include standard headers
#define GLM_FORCE_RADIANS
////Memory Leak
#include <stdlib.h>
#include "vld.h"
//#define _DEBUG

#include <fstream>
#include <iostream>

#include <vector>
#include <stdio.h>
#define TESTVAR 1.63
// If the evaluated a is bigger then the evaluated b take evaluated a
//#define CALL_WITH_MAX(a,b)f((a)>(b)?(a):(b););
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

// 
template<typename T>
inline T callWithMax(const T& a,const T& b){
	return f(a>b?a:b);
}

const float testVar = 1.63;
int f(int a){return a;};

class classB{

public:
	classB(int i){
		//NumTurns2 = 2;		
		std::cout<<"B works. i is: "<<i<<std::endl;
		count.resize(NumTurns2);
		std::cout<<"Dimension of count is "<<count.size()<<std::endl;
		std::cout<<"Dimension of count is "<<count2[4]<<std::endl;
	};
	~classB(){};

	
private:
	static const int NumTurns = -1;
	// enum-hack - makes NumTurn2 a symbollic name for 5
	enum { NumTurns2 = 5 };

	//static const int NumTurns2;
	std::vector<int> count;
	int count2[NumTurns2];
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
	
	int count;
};


//using namespace std;
int main(void){
	classB testB(2);
	//const int classB::NumTurns2 = 2;
	classC testC1(1);
	std::cout<<&(classC::NumTurns)<<std::endl;

	const int aa=20;
	enum{aaa=20};
	std::cout<<"aaa: "<<aaa<<std::endl;
	std::cout<<"&aaa: "<<&aa<<std::endl;
	int a1 = 1,b1=0;
	std::cout<<"a1: "<<a1<<std::endl;
	std::cout<<"CALL_WITH_MAX Evaluation b1 is smaller: "<<CALL_WITH_MAX(++a1,b1)<<std::endl;
	std::cout<<"CALL_WITH_MAX Evaluation b1 is bigger: "<<CALL_WITH_MAX(++a1,b1+10)<<"\ta1: "<<a1<<std::endl;
	std::cout<<"CALL_WITH_MAX Evaluation b1 is bigger: "<<CALL_WITH_MAX(a1++,b1)<<"\ta1: "<<a1<<std::endl;

	int a2 = 1,b2=0;
	std::cout<<"a2: "<<a2<<std::endl;
	std::cout<<"callWithMax Evaluation b2 is smaller: "<<callWithMax(++a2,b2)<<std::endl;
	std::cout<<"callWithMax Evaluation b2 is bigger: "<<callWithMax(++a2,b2+10)<<"\ta2: "<<a2<<std::endl;
	std::cout<<"callWithMax Evaluation b2 is bigger: "<<callWithMax(a2++,b2)<<"\ta2: "<<a2<<std::endl;


	system("Pause");
}