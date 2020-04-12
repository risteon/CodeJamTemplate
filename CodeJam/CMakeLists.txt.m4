cmake_minimum_required(VERSION 3.1)

project(PROJECT_NAME)
set(CMAKE_BUILD_TYPE Debug)
add_definitions(-DLOCAL)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

