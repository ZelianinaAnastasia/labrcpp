#include <iostream>
#include <algorithm> 

//base class from task 2
class DynamicIntArray {
private:
    int* arr;
    int size;

public:
    //constructor
    DynamicIntArray(int size);

    //destructor
    ~DynamicIntArray();

    //copying constructor
    DynamicIntArray(const DynamicIntArray& other);

    //outputting array
    void print();

    //getter
    int get(int index);

    //setter
    void set(int index, int value);

    //size getting
    int get_size();

    //array pointer for sorting
    int* get_array();
};

//derived class with added methods
class ExtendedDynamicIntArray : public DynamicIntArray {
public:
    //constructors
    ExtendedDynamicIntArray(int size) : DynamicIntArray(size) {}

    //copying constructors
    ExtendedDynamicIntArray(const ExtendedDynamicIntArray& other) : DynamicIntArray(other) {}

    //mean value
    double average();

    //median value
    double median();

    //min value element
    int min();

    //max value element
    int max();
};
