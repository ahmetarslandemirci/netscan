#ifndef SCANNER_H
#define SCANNER_H
#include <iostream>
#include <string>

class Scanner
{
public:
    explicit Scanner(std::string ipRange);

    enum ScannerType { TCP=1, UDP, ICMP };

private:
    ScannerType scannerType;
    std::string ipRange;
};

#endif // SCANNER_H
