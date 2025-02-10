#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class PackageManager {
private:
    std::string language;

    void loadLanguage() {
        std::ifstream infile("config.txt");
        if (infile.is_open()) {
            std::getline(infile, language);
            infile.close();
        } else {
            language = "Eng";
        }
    }

    void saveLanguage() {
        std::ofstream outfile("config.txt");
        if (outfile.is_open()) {
            outfile << language;
            outfile.close();
        }
    }

public:
    PackageManager() {
        loadLanguage();
    }

    void setLanguage(const std::string& lang) {
        language = lang;
        saveLanguage();
        std::cout << "Language set to " << lang << std::endl;
    }

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

    void upgradePackages() {
        std::cout << "Upgrading packages..." << std::endl;
        system("sudo apt-get upgrade -y");
    }

    void autoremovePackages() {
        std::cout << "Autoremoving packages..." << std::endl;
        system("sudo apt-get autoremove -y");
    }

    void cleanPackages() {
        std::cout << "Cleaning packages..." << std::endl;
        system("sudo apt-get clean");
    }

    void holdPackage(const std::string& packageName) {
        std::cout << "Holding package: " << packageName << std::endl;
        std::string command = "sudo apt-mark hold " + packageName;
        system(command.c_str());
    }

    void unholdPackage(const std::string& packageName) {
        std::cout << "Unholding package: " << packageName << std::endl;
        std::string command = "sudo apt-mark unhold " + packageName;
        system(command.c_str());
    }

    void packageInfo(const std::string& packageName) {
        std::cout << "Getting information for package: " << packageName << std::endl;
        std::string command = "apt-cache show " + packageName;
        system(command.c_str());
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
    } else if (command == "install" && argc == 3) {
        pm.installPackage(argv[2]);
    } else if (command == "remove" && argc == 3) {
        pm.removePackage(argv[2]);
    } else if (command == "search" && argc == 3) {
        pm.searchPackage(argv[2]);
    } else if (command == "update") {
        pm.updatePackageList();
    } else if (command == "upgrade") {
        pm.upgradePackages();
    } else if (command == "autoremove") {
        pm.autoremovePackages();
    } else if (command == "clean") {
        pm.cleanPackages();
    } else if (command == "hold" && argc == 3) {
        pm.holdPackage(argv[2]);
    } else if (command == "unhold" && argc == 3) {
        pm.unholdPackage(argv[2]);
    } else if (command == "list-installed") {
        pm.listInstalledPackages();
    } else if (command == "info" && argc == 3) {
        pm.packageInfo(argv[2]);
    } else if (command == "set" && argc == 4 && std::string(argv[2]) == "lang") {
        pm.setLanguage(argv[3]);
    } else {
        std::cerr << "Unknown command: " << command << std::endl;
        std::cerr << "Available commands: list, install, remove, search, update, upgrade, autoremove, clean, hold, unhold, list-installed, info, set lang <language>" << std::endl;
        return 1;
    }

    return 0;
}