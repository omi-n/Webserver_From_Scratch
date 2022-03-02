//
// Created by Nabil on 2/26/2022.
//

#ifndef WSLWEBSERVER_REQUEST_H
#define WSLWEBSERVER_REQUEST_H

#include <string>


class Request {
public:

private:
    struct RequestLine* requestLine;
    struct RequestHeader* requestHeader;
};

struct RequestLine {
    std::string method;
    std::string resource;
    std::string protocol;
};

struct RequestHeader {
    std::string host;
    std::string user_agent;
    std::string accept;
};



#endif //WSLWEBSERVER_REQUEST_H
