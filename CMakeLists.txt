cmake_minimum_required(VERSION 3.22)
project(WSLWebServer)

set(CMAKE_CXX_STANDARD 14)

add_library(WSLWebServer WebServer.cpp network/SimpleSocket.cpp network/SimpleSocket.h network/BindingSocket.cpp network/BindingSocket.h)
