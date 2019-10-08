#ifndef cool_test_TestTemplate_hpp
#define cool_test_TestTemplate_hpp

#include <iostream>

namespace cool_test {

    template<typename T>class TestTemplate {
        public:
            TestTemplate(){
                
            };
            TestTemplate(T *t){
                this->t = t; 
                t->say();
            };
            ~TestTemplate(){
                delete t;
            };
        public:
            T *t;
    };
    class TestTemplateFunc {
        public: 
            template<typename T> void  getTemplateFunc(T t){
                std::cout<< "template func:" << t << std::endl;
            }

    };
}

#endif
