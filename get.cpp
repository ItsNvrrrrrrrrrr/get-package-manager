#include <iostream>
#include <cstdlib>
#include <string>

class PackageManager {
public:
    void listAvailablePackages() {
        std::cout << "Listing available packages..." << std::endl;
        system("apt-cache search .");
    }

    void listInstalledPackages() {
        std::cout << "Listing installed packages..." << std::endl;
        system("dpkg --list");
    }

    void installPackage(const std::string& packageName) {
        std::cout << "Installing package: " << packageName << std::endl;
        std::string command = "sudo apt-get install -y " + packageName;
        system(command.c_str());
    }

    void removePackage(const std::string& packageName) {
        std::cout << "Removing package: " << packageName << std::endl;
        std::string command = "sudo apt-get remove -y " + packageName;
        system(command.c_str());
    }

    void searchPackage(const std::string& packageName) {
        std::cout << "Searching for package: " << packageName << std::endl;
        std::string command = "apt-cache search " + packageName;
        system(command.c_str());
    }

    void updatePackageList() {
        std::cout << "Updating package list..." << std::endl;
        system("sudo apt-get update");
    }
};

int main(int argc, char* argv[]) {
    PackageManager pm;

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <command> [<args>]" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "list") {
        pm.listAvailablePackages();
    } else if (command == "package" && argc == 3) {
        pm.installPackage(argv[2]);
    } else if (command == "rmpack" && argc == 3) {
        pm.removePackage(argv[2]);
    } else if (command == "search" && argc == 3) {
        pm.searchPackage(argv[2]);
    } else if (command == "update") {
        pm.updatePackageList();
    } else if (command == "list-installed") {
        pm.listInstalledPackages();
    } else {
        std::cout << "Unknown command: " << command << std::endl;
        std::cout << "Available commands: list, package, remove, search, update, list-installed" << std::endl;
    }

    return 0;
}