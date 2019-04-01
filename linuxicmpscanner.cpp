#include "linuxicmpscanner.h"

LinuxICMPScanner::LinuxICMPScanner(std::string ipRange) : Scanner(ipRange){

}

void LinuxICMPScanner::scan() {
    std::cout << "Im scanning for linux" << std::endl;
}
