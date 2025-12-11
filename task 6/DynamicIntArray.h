#include <iostream>

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

    //end adding
    void push_back(int value);

    //array sum
    void add(DynamicIntArray& other);

    //array substraction
    void subtract(DynamicIntArray& other);

    //size get
    int get_size();
};
