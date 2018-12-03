#include "C:\Software\Luxor\hw_interface\src\stages\stage_opcua_festo\Festo-comm-lib\include\festo_udp_func.h"
#include "udp_func.h"
//#include "udp_messages.h"
//#include "boost/asio.hpp"
//#include "boost/array.hpp"
//#include <assert.h>
//#include <chrono>
//#include <thread>
//#include <vector>
//#include <exception>
#include <iostream>

eUdpStatus LuxorSendTriggerWaitResponse(std::string ip, std::string port) {
  eUdpStatus status = eUdpStatus::UDP_STATUS_ERROR_UNKNOWN;
  try {
    // open connection
    boost::asio::io_service                 io_service;
    boost::asio::ip::udp::resolver          resolver(io_service);
    boost::asio::ip::udp::resolver::query   query(boost::asio::ip::udp::v4(), ip, port);

    boost::asio::ip::udp::endpoint          remote_endpoint = *resolver.resolve(query);

    boost::asio::ip::udp::socket            socket(io_service);
    socket.open(boost::asio::ip::udp::v4());


    // Send trigger request
    udp_message_data request_data;
    udp::send_message(socket, remote_endpoint, UDP_FRAME_TYPE_TRIGGER_REQUEST, request_data);

    // Recieve status
    boost::array<udp_message, 1> recv_buf;
    boost::asio::ip::udp::endpoint sender_endpoint;
    socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);   // blocks until package is received

    if (!udp::test_checksum(recv_buf[0]))
      throw(std::runtime_error("Package received by luxor has wrong checksum"));
    if (recv_buf[0].data.trigger_response.result != eUdpStatus::UDP_STATUS_OK) {
        throw(std::runtime_error("Package received from luxor does not have status UDP_STATUS_OK"));
    }
    if (recv_buf[0].header.frame_type != UDP_FRAME_TYPE_TRIGGER_RESPONSE_6DOF) {
      status = UDP_STATUS_ERROR_UNKNOWN_FRAME_TYPE;
      std::cout << "\n---\nException:\nframe_type: " << recv_buf[0].header.frame_type
        << "\nid: " << recv_buf[0].header.frame_id << std::endl;
      throw(std::runtime_error(std::string("Package received from luxor does not have frametype 510")));
      std::cout << "---\n\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    throw;
  }
  return status;
}



eUdpStatus LuxorStartAquisition(std::string ip, std::string port) {
  eUdpStatus status = eUdpStatus::UDP_STATUS_OK;
  try {
    // open connection
    boost::asio::io_service                 io_service;
    boost::asio::ip::udp::resolver          resolver(io_service);
    boost::asio::ip::udp::resolver::query   query(boost::asio::ip::udp::v4(), ip, port);

    boost::asio::ip::udp::endpoint          remote_endpoint = *resolver.resolve(query);

    boost::asio::ip::udp::socket            socket(io_service);
    socket.open(boost::asio::ip::udp::v4());


    // Send trigger request
    udp_message_data request_data;
    udp::send_message(socket, remote_endpoint, UDP_FRAME_TYPE_ACQ_START_REQUEST, request_data);

    // Recieve status
    boost::array<udp_message, 1> recv_buf;
    boost::asio::ip::udp::endpoint sender_endpoint;
    socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);   // blocks until package is received

    if (!udp::test_checksum(recv_buf[0]))
      throw(std::runtime_error("Package received by luxor has wrong checksum"));
    if (recv_buf[0].data.trigger_response.result != eUdpStatus::UDP_STATUS_OK) {
        throw(std::runtime_error("Package received from luxor does not have status UDP_STATUS_OK"));
    }
    if (recv_buf[0].header.frame_type != UDP_FRAME_TYPE_ACQ_START_RESPONSE) {
      status = UDP_STATUS_ERROR_UNKNOWN_FRAME_TYPE;
      std::cout << "\n---\nException:\nframe_type: " << recv_buf[0].header.frame_type
        << "\nid: " << recv_buf[0].header.frame_id << std::endl;
      throw(std::runtime_error(std::string("Package received from luxor does not have frametype 507")));
      std::cout << "---\n\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    throw;
  }
  return status;
}

eUdpStatus LuxorStopAquisition(std::string ip, std::string port) {
  eUdpStatus status = eUdpStatus::UDP_STATUS_OK;
  try {
    // open connection
    boost::asio::io_service                 io_service;
    boost::asio::ip::udp::resolver          resolver(io_service);
    boost::asio::ip::udp::resolver::query   query(boost::asio::ip::udp::v4(), ip, port);

    boost::asio::ip::udp::endpoint          remote_endpoint = *resolver.resolve(query);

    boost::asio::ip::udp::socket            socket(io_service);
    socket.open(boost::asio::ip::udp::v4());


    // Send trigger request
    udp_message_data request_data;
    udp::send_message(socket, remote_endpoint, UDP_FRAME_TYPE_ACQ_STOP_REQUEST, request_data);

    // Recieve status
    boost::array<udp_message, 1> recv_buf;
    boost::asio::ip::udp::endpoint sender_endpoint;
    socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);   // blocks until package is received

    if (!udp::test_checksum(recv_buf[0]))
      throw(std::runtime_error("Package received by luxor has wrong checksum"));
    if (recv_buf[0].data.trigger_response.result != eUdpStatus::UDP_STATUS_OK) {
        throw(std::runtime_error("Package received from luxor does not have status UDP_STATUS_OK"));
    }
    if (recv_buf[0].header.frame_type != UDP_FRAME_TYPE_ACQ_STOP_RESPONSE) {
      status = UDP_STATUS_ERROR_UNKNOWN_FRAME_TYPE;
      std::cout << "\n---\nException:\nframe_type: " << recv_buf[0].header.frame_type
        << "\nid: " << recv_buf[0].header.frame_id << std::endl;
      throw(std::runtime_error(std::string("Package received from luxor does not have frametype 508")));
      std::cout << "---\n\n";
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    throw;
  }
  return status;
}
