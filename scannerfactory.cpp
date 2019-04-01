#include "scannerfactory.h"
#include <string>

#ifdef _WIN32
#include "windowsicmpscanner.h"
#elif __linux__
#include "linuxicmpscanner.h"
#endif


Scanner* ScannerFactory::getScanner(std::string ipRange) {
    Scanner *scanner = nullptr;
#ifdef _WIN32
    scanner = new WindowsICMPScanner(ipRange);
#elif __linux__
    scanner = new LinuxICMPScanner(ipRange);
#endif
    return scanner;
}
