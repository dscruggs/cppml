#ifndef __DATA_HANDLER_H
#define __DATA_HANDLER_H

#include <fstream> //file io
#include "stdint.h" //uint8_t data type
#include "data.hpp" //header
#include <vector> //vector
#include <string> //using strings
#include <map> //map class label to enumerated value
#include <unordered_set> //keep track of indexes as we split data between train,test,validate


class data_handler
{
    std::vector<data *> * data_array; //all of data pre-split
    std::vector<data *> * train_data;
    std::vector<data *> * test_data;
    std::vector<data *> * validation_data;

    int num_classes;
    int feature_vector_size;
    std::map<uint8_t, int> class_map; //each class will have an enumerated value

    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.20;
    const double VALIDATION_SET_PERCENT = 0.05;

    public:
    data_handler();
    ~data_handler();

    void read_feature_vector(std::string path);
    void read_feature_labels(std::string path);
    void split_data(); //splits data into train test validation sets according to percents
    void count_classes();

    uint32_t convert_to_little_endian(const unsigned char* bytes);

    std::vector<data *> * get_train_data();
    std::vector<data *> * get_test_data();
    std::vector<data *> * get_validation_data();
    
};

#endif