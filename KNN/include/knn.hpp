#ifndef __KNN_H
#define __KNN_H

#include <vector>
#include "C:/cygwin64/home/dscru/machine_learning/mnist_ml/include/data.hpp"

class Knn
{
    int k;
    std::vector<data *> * neighbors;
    std::vector<data *> * train_data;
    std::vector<data *> * test_data;
    std::vector<data *> * validation_data;

    public:
        Knn(int);
        Knn();
        ~Knn();

    void find_knearest(data *query_point);
    void set_train_data(std::vector<data *> *vect);
    void set_test_data(std::vector<data *> *vect);
    void set_validation_data(std::vector<data *> *vect);
    void set_k(int val);

    int predict(); //finds most frequent class, most fitting class
    double calculate_distance(data* query_point, data* input);
    double validate_performance();
    double test_performance();


};

#endif