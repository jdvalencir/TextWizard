#ifndef FILEMANAGERWIZARD_H
#define FILEMANAGERWIZARD_H

#include <optional>
#include <string>
#include <vector>
#include <fstream>

class FileManagerWizard {
    private:
        std::string filename;
        std::vector<std::string> lines;

        bool fileExists(const std::string& filepath);

    public:
        FileManagerWizard(const char* filename);
        std::vector<std::string> loadFile();
        void printFile();
        void saveCompressedFile(const std::vector<std::string>& lines, const std::string& outputPath);
};

#endif // FILEMANAGERWIZARD_H
