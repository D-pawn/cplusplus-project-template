#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
using namespace std;



#include "global/test_global.h"
static int testInt;

void testIntFunc(){
    std::cout << "global::testInt = " << testInt << std::endl;
}

int testReturnInt(){
    std::cout << "global::testReturnInt" << std::endl;
}

void get(string &hostname, string &ip) {
        char hname[128];
            memset(hname, 0x00, sizeof(char)*128);
                struct hostent *hent;

                    gethostname(hname, sizeof(hname));
                        hent = gethostbyname(hname);
                            hostname = hent->h_name;
                                ip = inet_ntoa(*(struct in_addr *)(hent->h_addr_list[0]));
}
