#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <vector>
#include <string>

class Generator{
    int size;
public:
    Generator(int size);
    std::vector<int> generate_sawtooth() ;
    std::vector<double> generate_standard_sin();
};

class FileReader {
public:
    virtual ~FileReader() = default;
    virtual bool read(const std::string &filename) = 0;
    virtual std::vector<double> get_data() = 0;
};

class Readertxt : public FileReader {
    std::vector<double> data;
public:
    bool read(const std::string &filename) override ;
    std::vector<double> get_data() override;
};

class Readerdata : public FileReader {

};

#endif // FILEUTILS_H
