//
// Created by Nabil on 3/2/2022.
//

#ifndef WSLWEBSERVER_SIMPLEPARSER_H
#define WSLWEBSERVER_SIMPLEPARSER_H

#include <string>
#include <cstdio>
#include <cstring>

namespace Nabil_Omi_WSL {

template <typename OutputType>
class SimpleParser {

public:
    explicit SimpleParser() = default;
    unsigned long getSize() { return size_; }
    OutputType getParsed() { return parsed_; }

    void setSize(unsigned long size) { size_ = size; }
    void setParsed(OutputType &parsed) { parsed_ = parsed; }

private:
    unsigned long size_;
    OutputType parsed_;

};

}



#endif //WSLWEBSERVER_SIMPLEPARSER_H
