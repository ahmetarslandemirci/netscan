#ifndef SCANNERFACTORY_H
#define SCANNERFACTORY_H
#include "scanner.h"
#include <string>

class ScannerFactory
{
public:
    static Scanner* getScanner(std::string ipRange);
};

#endif // SCANNERFACTORY_H
