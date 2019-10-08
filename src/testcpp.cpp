#include <iostream>

#include "Test.h"
#include "template/TestTemplate.hpp"
#include "global/test_global.h"

using namespace std;

void test(){
    string hostname;
    string ip; 
    get(hostname, ip);
    cout << hostname << "------------:" << ip <<endl;
}

int main(){
	test();	
	cout << "main done!" << endl;
}
