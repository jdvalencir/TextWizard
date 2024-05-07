#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <vector>
#include <string>

class Compression {
public:
    static std::vector<std::string> decompress(const std::string& path);
    static void compress(const std::vector<std::string>& lines, const std::string& outputPath);
};

#endif // COMPRESSION_H
