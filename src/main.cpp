
//This include needs to be first, else errors about redefinitions in winsock etc appear... 
//As good as Zmq is... The C++ implementation could use some love :/
#include <zhelpers.hpp>

#include <iostream>
#include <string>
#include <thread>

const std::string FRONTENDADDRESS = "tcp://*:21743";
const std::string BACKENDADDRESS = "tcp://*:21744";
const std::string envelope = "EasyErgsocket";

int main()
{
    std::cout << "Initing network..." << std::endl;
    
    zmq::context_t context(1);
    
    //Socket facing clients
    zmq::socket_t frontend (context, ZMQ_PUB);
    frontend.bind(FRONTENDADDRESS.c_str());
    std::cout << "Frontend bound to " << FRONTENDADDRESS << ", connect SUBs to this port" << std::endl;

    //Socket facing services
    zmq::socket_t backend (context, ZMQ_SUB);
    zmq_bind (backend, BACKENDADDRESS.c_str());
    backend.setsockopt(ZMQ_SUBSCRIBE, envelope.c_str(), envelope.size());
    std::cout << "Backend bound to " << BACKENDADDRESS << ", connect PUBs to this port" << std::endl;

    //  Start built-in device
    std::cout << "Starting forwarder..." << std::endl;
    zmq_device (ZMQ_FORWARDER, frontend, backend); //this is a blocking call...
    
    return 0;
}
