#ifndef WINDOWSICMPSCANNER_H
#define WINDOWSICMPSCANNER_H
#include "scanner.h"
#include <string>

class WindowsICMPScanner : public Scanner
{
public:
    WindowsICMPScanner(std::string ipRange);

    void scan();
};

#endif // WINDOWSICMPSCANNER_H
