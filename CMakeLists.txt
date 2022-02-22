cmake_minimum_required(VERSION 3.22)
project(WSLWebServer)

set(CMAKE_CXX_STANDARD 14)

add_library(WSLWebServer WebServer.cpp network/socket/SimpleSocket.cpp network/socket/SimpleSocket.h network/socket/BindingSocket.cpp network/socket/BindingSocket.h network/socket/ConnectingSocket.cpp network/socket/ConnectingSocket.h network/socket/ListeningSocket.cpp network/socket/ListeningSocket.h network/socket/webserver_sockets.cpp network/socket/webserver_sockets.h network/webserver_networking.cpp network/webserver_networking.h network/server/SimpleServer.cpp network/server/SimpleServer.h network/server/Server.cpp network/server/Server.h test.cpp)
