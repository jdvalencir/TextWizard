#include "Compression.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include <bitset>
#include <sstream>

void Compression::compress(const std::vector<std::string>& lines, const std::string& outputPath) {
    std::ostringstream oss;
    for (const auto& line : lines) {
        oss << line << '\n';
    }
    std::string contents = oss.str();

    std::cout << "Original content:" << std::endl;
    std::cout << contents << std::endl;

    std::map<std::string, int> dictionary;
    for (int i = 0; i < 256; i++) {
        dictionary[std::string(1, char(i))] = i;
    }

    std::string w;
    std::vector<int> compressed;
    for (char c : contents) {
        std::string wc = w + c;
        if (dictionary.count(wc)) {
            w = wc;
        } else {
            compressed.push_back(dictionary[w]);
            if (dictionary.size() < 4096) {
                dictionary[wc] = dictionary.size();
            }
            w = std::string(1, c);
        }
    }

    if (!w.empty()) {
        compressed.push_back(dictionary[w]);
    }

    std::ofstream output(outputPath, std::ios::binary);
    if (!output.is_open()) {
        throw std::runtime_error("Cannot open file for writing.");
    }

    for (int code : compressed) {
        output.write(reinterpret_cast<const char*>(&code), sizeof(int));
    }

    output.close();

    std::cout << "Compressed data:" << std::endl;
    for (int code : compressed) {
        std::cout << code << " ";
    }
    std::cout << std::endl;
}


std::vector<std::string> Compression::decompress(const std::string& path) {
    std::ifstream input(path, std::ios::binary);
    if (!input.is_open()) {
        throw std::runtime_error("Cannot open compressed file.");
    }

    std::vector<std::string> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary.push_back(std::string(1, char(i)));
    }

    std::string result;
    int prevCode = -1;
    int code;
    while (input.read(reinterpret_cast<char*>(&code), sizeof(int))) {
        std::string entry;
        if (code < dictionary.size()) {
            entry = dictionary[code];
        } else if (code == dictionary.size()) {
            entry = dictionary[prevCode] + dictionary[prevCode][0];
        } else {
            throw std::runtime_error("Decompression error: invalid code.");
        }

        result += entry;

        if (prevCode != -1 && dictionary.size() < 4096) {
            dictionary.push_back(dictionary[prevCode] + entry[0]);
        }
        prevCode = code;
    }

    std::vector<std::string> lines;
    std::string line;
    std::istringstream iss(result);
    while (std::getline(iss, line)) {
        lines.push_back(line);
    }

    input.close();
    return lines;
}










