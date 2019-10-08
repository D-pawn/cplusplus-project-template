#include <iostream>

#include "Test.h"
#include "TestTemplate.h"

namespace cool_test {

    template<typename T> TestTemplate<T>::TestTemplate(){
         
    }
    template<typename T> TestTemplate<T>::TestTemplate(T *t){
        this.t = t;
        t.say();
    }

    template<typename T> TestTemplate<T>::~TestTemplate(){
    }

}
