cmake_minimum_required(VERSION 3.13)

project(HelloWindow)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} base)