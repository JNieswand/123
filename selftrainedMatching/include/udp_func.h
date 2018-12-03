#include "udp_messages.h"
#include "boost/asio.hpp"
#include "boost/array.hpp"
#include <assert.h>
#include <chrono>
#include <thread>
#include <vector>
#include <exception>



// Starts Luxor 3D Aquisition, does wait for answer
extern eUdpStatus LuxorStartAquisition(std::string ip, std::string port);

// Stops Luxor 3D Aquisition, does wait for answer
extern eUdpStatus LuxorStopAquisition(std::string ip, std::string port);

extern eUdpStatus LuxorSendTriggerWaitResponse(std::string ip, std::string port);
