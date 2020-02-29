#include "C:/cygwin64/home/dscru/machine_learning/mnist_ml/include/MLlibrary.hpp"


int main()
{
    data_handler *dh = new data_handler();
    dh->read_feature_vector("../data/train-images-idx3-ubyte");
    dh->read_feature_labels("../data/train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();
    Knn *knearest = new Knn();
    knearest->set_train_data(dh->get_train_data());
    knearest->set_test_data(dh->get_test_data());
    knearest->set_validation_data(dh->get_validation_data());
    double performance = 0.0;
    double best_performance = 0.0;
    printf("Finding best k.\n");
    int best_k = 1;
    for (int i=1;i<=4;i++)
    {
        if (i==1)
        {
            knearest->set_k(i);
            performance = knearest->validate_performance();
            best_performance = performance;
        }
        else
        {
            knearest->set_k(i);
            performance = knearest->validate_performance();
            if (performance > best_performance) 
            {
                best_performance = performance;
                best_k=i;
            }  
        }
    }
    printf("Finished! Best k is %d.\n",best_k);
    knearest->set_k(best_k);
    knearest->test_performance();
}