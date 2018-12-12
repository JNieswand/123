#include "udp_messages.h"
#include "boost/asio.hpp"
#include "boost/array.hpp"
#include <assert.h>
#include <chrono>
#include <thread>
#include <vector>
#include <exception>



// Sends a trigger request, waits for answer and returns 6D pose if found
extern eUdpStatus LuxorTrigger6DPose(std::array<float, 6>& pose, std::string ip, std::string port);

extern eUdpStatus LuxorSendTriggerWaitResponse(std::string ip, std::string port);

extern bool LuxorStatusOK(std::string ip, std::string port);

