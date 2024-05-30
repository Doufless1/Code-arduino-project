#!/bin/sh
mkdir bin
cd bin
cmake -D CMAKE_TOOLCHAIN_FILE=../Arduino-CMake-Toolchain/Arduino-toolchain.cmake ../Project_System_GitHub
cmake --build . --target upload-Project_Systems -- SERIAL_PORT=/dev/ttyUSB0
