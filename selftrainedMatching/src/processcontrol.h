#ifndef PROCESSCONTROL_H
#define PROCESSCONTROL_H
#include <string>
#include <sstream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
class ProcessControl
{
public:
    ProcessControl();
    void startprocess();
    void ScanObject();
    void DetectObject();
    void Trigger();
    void setIp(std::string input="127.0.0.1"){m_luxor_udp_ip=input;}
    void setPort(std::string input="20123"){m_luxor_udp_port=input;}
    void setAquisitionModes(std::string input1= "Mode1", std::string input2= "Mode2"){
        m_luxor_aquisition_mode_1 = input1;
        m_luxor_aquisition_mode_2 = input2;}
    void setModelPath(std::string input= "C:/Users/dbutov/Desktop/Jacob_Demo_selftrained/model_path/trained_model.ply"){
        m_model_path = boost::filesystem::path(input);}
    void switchAquisitionMode(std::string aquistion_mode);
    std::ostringstream m_Status;

protected:
        std::string m_luxor_udp_ip;
        std::string m_luxor_udp_port;
        std::string m_luxor_aquisition_mode_1;
        std::string m_luxor_aquisition_mode_2;
        std::string m_luxor_aquisition_mode_active;
        boost::filesystem::path m_model_path;
};


#endif // PROCESSCONTROL_H
