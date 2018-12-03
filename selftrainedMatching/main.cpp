#include <iostream>
#include <stdlib.h>
#include "C:\Software\Luxor\hw_interface\src\stages\stage_opcua_festo\Festo-comm-lib\include\festo_udp_func.h"
//#include "C:\Qt\5.9.2\msvc2013_64\include\QtCore\qstring.h"
//#include <QString>
#include <string>
#include <time.h>
#include "udp_func.h"
using namespace std;

int main()
{
    string luxor_udp_ip, luxor_udp_port;
    luxor_udp_ip = "127.0.0.1";
    luxor_udp_port = "20123";
    std::cout << "Hello World!" << endl;
    LuxorSwitchAquisitionMode("Mode1",luxor_udp_ip, luxor_udp_port);
    std::chrono::milliseconds timespan(1000);
    std::this_thread::sleep_for(timespan);
    std::cout << "Aquisition Mode switched" << endl;
    int ans = 2;
    while( ans == 2){
        std::cout << "trigger..."<<std::endl;
//        LuxorSendTriggerWaitResponse(luxor_udp_ip,luxor_udp_port);
        LuxorSendTriggerRequest(luxor_udp_ip, luxor_udp_port);        std::cout<< " sent trigger request."<<std::endl;
        std::cout << "If ok, press 1. New Trigger: 2. cancel: 0 :";
        std::cin >> ans;
    }
    if (ans == 0){
        std::cout<< "abort."<<std::endl;
        return 0;
    }
    LuxorSwitchAquisitionMode("Mode2",luxor_udp_ip, luxor_udp_port);
    std::array<float,6> pose;
    LuxorTriggerAndReceive6DPose(pose,luxor_udp_ip, luxor_udp_port);
//    std::cout << "Luxor Triggered" << endl;
//    LuxorStartAquisition(luxor_udp_ip, luxor_udp_port);
//    LuxorSendTriggerRequest(luxor_udp_ip, luxor_udp_port);
//    std::sleep(3000);
//    LuxorStopAquisition(luxor_udp_ip, luxor_udp_port);

    return 0;
}
