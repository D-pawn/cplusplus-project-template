
#include "Test.h"

namespace cool_test {
    int testInt;

    void testIntFunc(){
            std::cout << "global::testInt = " << testInt << std::endl;
    }
    TestClass::TestClass(){
		std::cout<< "TestClass construct" << std::endl;
	};
	TestClass::~TestClass(){
		std::cout<< "TestClass destruct,index:" << index << std::endl;
	};
	void TestClass::say(){
        int testInt();
		std::cout<< "TestClass testInt = " << testInt << std::endl;
    //    const char* filename = "../config/test.txt"; 
    //    FILE* fp = fopen(filename, "r");
	//	std::cout<< "TestClass say: index: " << index << ",fp: " << fp << std::endl;
	}
	void TestClass::release(){
		delete this;
	}
}

