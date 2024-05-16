cmake_minimum_required(VERSION 3.19)
project(Project_Systems LANGUAGES CXX)

add_executable(${PROJECT_NAME} 
	testing.cpp
)

target_link_arduino_libraries(${PROJECT_NAME} PRIVATE core Wire)
target_enable_arduino_upload(${PROJECT_NAME})
