#include "processcontrol.h"
#include "processply.h"
#include "udp_func.h"
#include <string>
#include <time.h>
#include "C:\Software\Luxor\hw_interface\src\stages\stage_opcua_festo\Festo-comm-lib\include\festo_udp_func.h"
ProcessControl::ProcessControl(){
    startprocess();
}
void ProcessControl::startprocess(){
    //set Params (default)
    setIp();
    setPort();
    setAquisitionModes();
    setModelPath();
    m_Status << "UDP ID : " << m_luxor_udp_ip<<std::endl
             <<"UDP Port : " << m_luxor_udp_port << std::endl
             << "Make sure that Luxor 3D Aquisition is running."<< std::endl
             << "Camera Settings-> Trigger to Software!"<<std::endl;
}
void ProcessControl::ScanObject(){
    switchAquisitionMode(m_luxor_aquisition_mode_1);
    try{
        LuxorSendTriggerWaitResponse(m_luxor_udp_ip,
                                     m_luxor_udp_port);
        m_Status<< "Sent trigger request."<<std::endl;
        Pointcloud pcld;
        pcld.setPath(m_model_path);
        pcld.setLuxorCloudsDirectory();
        pcld.processply();
    }
    catch(...){
        m_Status << "Oups! Could not trigger.\n";
        //    LuxorSendTriggerRequest(m_luxor_udp_ip, m_luxor_udp_port);
    }
}

void ProcessControl::DetectObject(){
    switchAquisitionMode(m_luxor_aquisition_mode_2);
    std::array<float,6> pose;
    try{
        LuxorTrigger6DPose(pose, m_luxor_udp_ip, m_luxor_udp_port);
        m_Status << "Luxor Triggered, object detected. See Data Analyser\n "
                 << "Under Luxor->Viewer for visualization"<< std::endl;
    }
    catch(...){
        m_Status << "Oups! Could not trigger or detect object.\n";
    }

}

void ProcessControl::Trigger(){
    bool status_ok = LuxorStatusOK(m_luxor_udp_ip, m_luxor_udp_port);
    if( status_ok){
        switchAquisitionMode(m_luxor_aquisition_mode_2);
//        LuxorSendTriggerRequest(m_luxor_udp_ip, m_luxor_udp_port);
//        std::cout<< "Sent trigger request."<<std::endl;
        LuxorSendTriggerWaitResponse(m_luxor_udp_ip,
                                     m_luxor_udp_port);
    }
    else{
        std::cout <<"Trigger request failed because Luxor is not\n"
                  <<" on UDP_STATUS_OK\n";
    }

}

void ProcessControl::switchAquisitionMode(std::string aquisition_mode){
    if(m_luxor_aquisition_mode_active==aquisition_mode){
        return;
    }
    try{
        LuxorSwitchAquisitionMode(aquisition_mode,
                                  m_luxor_udp_ip,
                                  m_luxor_udp_port);
    }
    catch (...){
        std::cout<<"No UDP connection could be established!Aborting.";
        throw;
    }
    m_luxor_aquisition_mode_active= aquisition_mode;
    m_Status << "Aquisition Mode switched to "<<aquisition_mode << std::endl;
}
