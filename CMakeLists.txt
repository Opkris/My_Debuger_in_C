cmake_minimum_required(VERSION 3.17)
project(Debug C)

set(CMAKE_C_STANDARD 11)

add_executable(Debug opdebugger.c pgdbglog.c include/pgdbglog.h)