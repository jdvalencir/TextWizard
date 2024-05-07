#include "FileManagerWizard.h"
#include "../Compression/Compression.h"

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

std::vector<std::string> FileManagerWizard::loadFile() {
    std::string path = filename;
    if (fileExists(path)) {
        lines = Compression::decompress(path);
        return lines;
    } else {
        std::cout << "File not found." << std::endl;
        return {};
    }
}


void FileManagerWizard::printFile() {
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
}

void FileManagerWizard::saveCompressedFile(const std::vector<std::string>& lines, const std::string& outputPath) {
    Compression::compress(lines, outputPath);
}


