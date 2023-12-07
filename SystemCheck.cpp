#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

bool IsRunningInVM() {
    // This function checks for BIOS vendor for commmon VM identififers

    std::ifstream biosFile("/sys/class/dmi/id/bios_vendor");
    std::string line;
    if (biosFile.is_open()) {
        while (getline(biosFile, line)) {
            if (line.find("VMware") != std::string::npos || 
                line.find("VirtualBox") != std::string::npos ||
                line.find("Hyper-V") != std::string::npos) {
                return true;
            }
        }
        biosFile.close();
    }

    return false;
}

int main() {
    if (IsRunningInVM()) {
        std::cout << "VM detected. Program will exit and delete itself." << std::endl;

        // Self-deletion logic (will probably change this)
        // remove("path_to_this_executable");

        return 0; // Exit the program
    }

    std::cout << "No VM detected. Proceeding with execution." << std::endl;

    // Continue 

    return 0;
}
