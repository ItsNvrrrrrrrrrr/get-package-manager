#include <iostream>
#include <cstdlib>
#include <string>

class PackageManager {
public:
    void listAvailablePackages() {
        std::cout << "Listing available packages..." << std::endl;
        if (std::system("apt-cache search .") != 0) {
            std::cerr << "Error: Failed to list available packages." << std::endl;
        }
    }

    void listInstalledPackages() {
        std::cout << "Listing installed packages..." << std::endl;
        if (std::system("dpkg --list") != 0) {
            std::cerr << "Error: Failed to list installed packages." << std::endl;
        }
    }

    void installPackage(const std::string& packageName) {
        std::cout << "Installing package: " << packageName << std::endl;
        std::string command = "sudo apt-get install -y " + packageName;
        if (std::system(command.c_str()) != 0) {
            std::cerr << "Error: Failed to install " << packageName << std::endl;
        }
    }

    void removePackage(const std::string& packageName) {
        std::cout << "Removing package: " << packageName << std::endl;
        std::string command = "sudo apt-get remove -y " + packageName;
        if (std::system(command.c_str()) != 0) {
            std::cerr << "Error: Failed to remove " << packageName << std::endl;
        }
    }

    void searchPackage(const std::string& packageName) {
        std::cout << "Searching for package: " << packageName << std::endl;
        std::string command = "apt-cache search " + packageName;
        if (std::system(command.c_str()) != 0) {
            std::cerr << "Error: Failed to search for " << packageName << std::endl;
        }
    }

    void updatePackageList() {
        std::cout << "Updating package list..." << std::endl;
        if (std::system("sudo apt-get update") != 0) {
            std::cerr << "Error: Failed to update package list." << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {
    PackageManager pm;

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <command> [<args>]" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "list") {
        pm.listAvailablePackages();
    } else if (command == "package" && argc == 3) {
        pm.installPackage(argv[2]);
    } else if (command == "remove" && argc == 3) {
        pm.removePackage(argv[2]);
    } else if (command == "search" && argc == 3) {
        pm.searchPackage(argv[2]);
    } else if (command == "update") {
        pm.updatePackageList();
    } else if (command == "list-installed") {
        pm.listInstalledPackages();
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        std::cerr << "Available commands: list, package, remove, search, update, list-installed" << std::endl;
        return 1;
    }

    return 0;
}
