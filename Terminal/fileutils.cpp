#include "fileutils.h"

Generator::Generator(int size) {
    this->size = size;
}

std::vector<int> Generator::generate_sawtooth() {
    std::vector<int> test_data(size);
    for(std::size_t i = 0; i < this->size; i++){
        test_data[i] = i % 10;
    }
    return test_data;
}

std::vector<double> Generator::generate_standard_sin(){
    std::vector<double> test_data(size);
    //for(size_t i = 0; i < size; i++){
    //    test_data = sin(i * 0.01);
    //}
    return test_data;
}

