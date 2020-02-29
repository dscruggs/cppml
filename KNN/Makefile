CC=g++
MNIST_ML_ROOT = C:/cygwin64/home/dscru/machine_learning/mnist_ml
SRC := $(MNIST_ML_ROOT)/KNN/src
CFLAGS := -std=c++11 -DEUCLID
INCLUDE_DIR := $(MNIST_ML_ROOT)/KNN/inlcude/*

all : main

main : $(SRC)/knn.cc
	 $(CC) $(CFLAGS) -o main $(SRC)/main.cc

clean :
	rm main