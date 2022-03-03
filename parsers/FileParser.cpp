//
// Created by Nabil on 3/2/2022.
//

#include "FileParser.h"

using namespace Nabil_Omi_WSL;

FileParser::FileParser(std::string &toParse) {
    std::ifstream file(toParse);
    std::string tmpRes;
    if(file.is_open()) {
        std::string line;
        while(getline(file, line)) {
            tmpRes += (line + "\n");
        }
        file.close();
    } else {
        printf("PARSING FAILED: Unable to open file in FileParser");
    }

    // I want size to specifically be the str len size of the c string
    const char* tmpRes_c = tmpRes.c_str();
    setSize(strlen(tmpRes_c));
    setParsed(tmpRes);
}
