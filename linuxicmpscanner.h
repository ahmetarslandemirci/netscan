#ifndef LINUXICMPSCANNER_H
#define LINUXICMPSCANNER_H
#include "scanner.h"
#include <string>

class LinuxICMPScanner : public Scanner
{
public:
    LinuxICMPScanner(std::string ip);

    void scan();
};

#endif // LINUXICMPSCANNER_H
