#include "FileManagerWizard.h"
// #include "Compression/Compression.h"

#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

FileManagerWizard::FileManagerWizard(const char* filename) : filename(filename) {
    // Constructor
}

bool FileManagerWizard::fileExists(const std::string& filepath) {
    return fs::exists(filepath);
}

void FileManagerWizard::loadFile() {
    std::string path = filename;
    if (fileExists(path)) {
        // Compression::decompress(path);
        std::ifstream file(path);
        std::string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cout << "Archivo no encontrado." << std::endl;
    }
}

void FileManagerWizard::printFile() {
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
}
