
//This include needs to be first, else errors about redefinitions in winsock etc appear... 
//As good as Zmq is... The C++ implementation could use some love :/
#include <zhelpers.hpp>

#include <iostream>
#include <string>
#include <thread>

const std::string FRONTENDADDRESS = "tcp://*:21743";
const std::string BACKENDADDRESS = "tcp://*:21744";

int main()
{
    std::cout << "Initing network..." << std::endl;
    
    zmq::context_t context(1);
    
    //  Socket facing clients
    zmq::socket_t frontend (context, ZMQ_PUB);
    frontend.bind(FRONTENDADDRESS.c_str());
    std::cout << "Frontend bound to " << FRONTENDADDRESS << std::endl;

    //  Socket facing services
    zmq::socket_t backend (context, ZMQ_SUB);
    zmq_bind (backend, BACKENDADDRESS.c_str());
    std::cout << "Backend bound to " << BACKENDADDRESS << std::endl;

    //  Start built-in device
    std::cout << "Starting forwarder..." << std::endl;
    zmq_device (ZMQ_FORWARDER, frontend, backend);
    
    std::cout << "Forwarder initialized, this message should never show due to the blocking nature of the zmq_device..." << std::endl;
/**
    while (1)
    {
        //yield the thread to allow other processes to access the CPU
        //if we do not do this we would hog the CPU 100%, which is not necessary
        std::this_thread::yield();
    }
**/
    return 0;
}
