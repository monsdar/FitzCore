# FitzCore
A simple Pub/Sub forwarder to act as a central communication point in Fitznet

## Build
This project uses [CMake](https://cmake.org) and [Conan.io](https://www.conan.io/) to provide an easy to use, portable build system.

After setting up CMake and Conan, the following could be used to build everything on a Windows machine with Visual Studio 2013:
```
cd FitzCore
mkdir build && cd build
conan install ../
cmake .. -G "Visual Studio 12 Win64"
cmake --build . --config Release --target Install
```
