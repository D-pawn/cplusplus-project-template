#ifndef test_TestSocket_hpp
#define test_TestSocket_hpp

#include <iostream>
#include <pthread.h>
#include <map>

namespace cool_test {

class TestSocket{
	public:
		void say_hello();
		void add_ref();
		void release_ref();
	public:
		int ref_cout;
	

};

void TestSocket::say_hello(){
	if(ref_cout==0){
		std::cout << "delete start!" << std::endl;
		delete this;
		std::cout << "bye bye!" << std::endl;
	}else{
		std::cout << "hello !" << ref_cout  << std::endl;
	}
};
void TestSocket::add_ref(){
	ref_cout++;
};
void TestSocket::release_ref(){
	ref_cout--;
	say_hello();
};


std::map<uint32_t, TestSocket*> handleMap;


static void* callback(void* args){
	TestSocket* testSocket=handleMap[0];
	if(testSocket==NULL){
		std::cout<<"get instance error from map"<<std::endl;
	}else{
		testSocket->say_hello();
	};
};

class TestSocketExecute{
	public:
		void test();
};

void TestSocketExecute::test(){
	TestSocket* testSocket=new TestSocket();
//	testSocket->ref_cout=0;
	TestSocket testSocket1;	
	std::cout << "test.int=" << testSocket1.ref_cout<< std::endl;	
	handleMap[0]=testSocket;

	const int thread_num=2;
    pthread_t tids[thread_num];

	for(int i=0;i<thread_num;i++){
		int ret = pthread_create(&tids[i],NULL,callback,NULL);	
		if(ret != 0){
			std::cout << "pthread_create error" << std::endl;	
		}
	}

	pthread_exit(NULL);
};

}

#endif
