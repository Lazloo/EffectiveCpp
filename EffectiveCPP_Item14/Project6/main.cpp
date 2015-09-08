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
#include <mutex>
#include <thread>

std::mutex mutexPtr;

std::mutex foo,bar;

class Lock{
public: 
	explicit Lock(std::mutex *pm):mutexPtrMember(pm){
		mutexPtrMember->lock();
		std::cout<<"Mutex Locked"<<std::endl;
	};

	~Lock(){
		mutexPtrMember->unlock();
		std::cout<<"Mutex unlocked"<<std::endl;
	};
	
private:
	// Make Copy Assignement private ... not allowed
	Lock & operator= (const Lock & other){};

	std::mutex *mutexPtrMember;
};

//class Lock2{
//public: 
//	explicit Lock2(std::mutex *pm):mutexPtrMember(pm,std::mutex::unlock()){
//		std::cout<<"Adresse Before Reset: "<<pm<<std::endl;
//		//mutexPtrMember.reset(pm);
//		std::cout<<"Adresse After Reset: "<<mutexPtrMember<<std::endl;
//		mutexPtrMember.get()->lock();
//		std::cout<<"After Lock Class"<<std::endl;
//	};
//
//	~Lock2(){
//		//mutexPtrMember.get()->unlock();
//			//->unlock();
//		std::cout<<"After Unlock Class"<<std::endl;
//	};
//	
//private:
//	// Make Copy Assignement private ... not allowed
//	Lock & operator= (const Lock & other){};
//
//	std::tr1::shared_ptr<std::mutex> mutexPtrMember;
//};

void testFctWorks(void) {
	std::cout<<"Before Lock"<<std::endl;
	//std::lock (foo,bar);
	mutexPtr.lock();
	std::cout<<"After Lock"<<std::endl;
	mutexPtr.unlock();
	std::cout<<"After Unlock"<<std::endl;
}

// This Function does not unlock the mutex
// This function can be called only from one thread otherwise dead end
void testFctDoNotWork(void) {
	std::cout<<"Before Lock"<<std::endl;
	mutexPtr.lock();
	std::cout<<"After Lock"<<std::endl;
	//mutexPtr.unlock();
	std::cout<<"After Unlock"<<std::endl;
}

void testFctLockClass(void) {
	class Lock lockRAII(&mutexPtr);
	class Lock lockRAII2(&foo);
	// Dead end since one class is deleted and therefore the mutex get forgotten
//	lockRAII = lockRAII2;
}

//void testFctLock2Class(void) {
//	std::mutex mutex1;
//	//std::mutex mutex2;
//	class Lock2 lockRAII(&mutex1);
//	//class Lock2 lockRAII2(&mutex2);
//	// Dead end since one class is deleted and therefore the mutex get forgotten
////	lockRAII = lockRAII2;
//}

int main(void){

	// locks too mutex object (mutexPtr,foo) using the defined Lock Class
	std::thread th1(testFctLockClass); // main and th1 are now running parallel
	th1.join(); // pauses until th1 finishes

	std::mutex m1, m2;
	//std::mutex m3;

	
	// Mutex Error as soon as program has ended
	std::lock(m1, m2);

	//std::mutex *mPtr1,*mPtr2;
	//std::lock(*mPtr1, *mPtr1);

	system("Pause");
	return 0;
}