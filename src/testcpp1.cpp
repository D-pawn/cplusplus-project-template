#include <iostream>
#include <string>
using namespace std;

class Demo{
public:
    Demo(string s);
    ~Demo();
private:
    string m_s;
};


int test(){
    //局部对象
    Demo obj3("3");
    //new创建的对象
    Demo *pobj4 = new Demo("4");
    cout<<"test"<<endl;
  
    return 0;
}
