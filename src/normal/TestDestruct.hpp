#ifndef test_TestDestruct_cpp
#define test_TestDestruct_cpp

#include <iostream> 

namespace cool_test {
    int test_1;
	class TestDestruct {
		public:
			TestDestruct();
			~TestDestruct();
			void say();
			void release();
		public:
            int TestDestruct=1;
			int index;
	};
	TestDestruct::TestDestruct(){
		std::cout<< "TestDestruct construct" << std::endl;
	};
	TestDestruct::~TestDestruct(){
		std::cout<< "TestDestruct destruct,index:" << index << std::endl;
	};
	void TestDestruct::say(){
		std::cout<< "TestDestruct say: index: " << index << std::endl;
	}
	void TestDestruct::release(){
		delete this;
	}

	class TestDestructChild : public TestDestruct{
		public:
			TestDestructChild();
			~TestDestructChild();	
			void say();
			void release();
	};

	TestDestructChild::TestDestructChild(){
		std::cout<< "TestDestructChild construct" << std::endl;
	};
	TestDestructChild::~TestDestructChild(){
		std::cout<< "TestDestructChild destruct" << std::endl;
	};
	void TestDestructChild::say(){
		std::cout<< "TestDestructChild say: index: " << index << std::endl;
	}

	void TestDestructChild::release(){
		delete this;
	}

	class TestDestructExecute {
		public:
			void test();

	};
	void TestDestructExecute::test(){
        TestDestruct testDestruct;
        testDestruct.index=0;
        TestDestruct testDestruct1=testDestruct;
        testDestruct1.index=1;

		testDestruct.say();
		testDestruct1.say();
        
		TestDestruct* testDestructPtr=new TestDestruct();
        testDestructPtr->index=-1;
        TestDestruct testDestructp1=*testDestructPtr;
        testDestructp1.index=-101;

		testDestructPtr->say();
		testDestructp1.say();
	};


}


#endif
