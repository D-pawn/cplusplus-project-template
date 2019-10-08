#ifndef cool_test_Test_h
#define cool_test_Test_h

#include <iostream>
#include <string>

namespace cool_test {

    void testIntFunc();

    class TestClass {
        public:
            TestClass();
            ~TestClass();
            void say();
            void release();
        public:
            int index;
            std::string desc;
    };
}

#endif
