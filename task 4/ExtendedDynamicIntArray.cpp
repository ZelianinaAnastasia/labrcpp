#include <iostream>
#include <algorithm> 

//base class from task 2
class DynamicIntArray {
private:
    int* arr;
    int size;

public:
    //constructor
    DynamicIntArray(int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    //destructor
    ~DynamicIntArray() {
        delete[] arr;
    }

    //copying constructor
    DynamicIntArray(const DynamicIntArray& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    //outputting array
    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    //getter
    int get(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Error 'index out of range'" << std::endl;
            return 0;
        }
        return arr[index];
    }

    //setter
    void set(int index, int value) {
        if (index < 0 || index >= size) {
            std::cout << "Error 'index out of range'" << std::endl;
            return;
        }
        if (value < -100 || value > 100) {
            std::cout << "Error 'element value out of range (-100, 100)" << std::endl;
            return;
        }
        arr[index] = value;
    }

    //size getting
    int get_size() {
        return size;
    }

    //array pointer for sorting
    int* get_array() {
        return arr;
    }
};

//derived class with added methods
class ExtendedDynamicIntArray : public DynamicIntArray {
public:
    //constructors
    ExtendedDynamicIntArray(int size) : DynamicIntArray(size) {}

    //copying constructors
    ExtendedDynamicIntArray(const ExtendedDynamicIntArray& other) : DynamicIntArray(other) {}

    //mean value
    double average() {
        if (get_size() == 0) {
            std::cout << "Error 'array is empty'" << std::endl;
            return 0;
        }

        double sum = 0;
        for (int i = 0; i < get_size(); i++) {
            sum += get(i);
        }
        return sum / get_size();
    }

    //median value
    double median() {
        if (get_size() == 0) {
            std::cout << "Error 'array is empty'" << std::endl;
            return 0;
        }

        //sorting array
        int* sorted_arr = new int[get_size()];
        for (int i = 0; i < get_size(); i++) {
            sorted_arr[i] = get(i);
        }
        std::sort(sorted_arr, sorted_arr + get_size());

        double result;
        if (get_size() % 2 == 1) {
            //for odd
            result = sorted_arr[get_size() / 2];
        }
        else {
            //for even
            int mid1 = sorted_arr[get_size() / 2 - 1];
            int mid2 = sorted_arr[get_size() / 2];
            result = (mid1 + mid2) / 2.0;
        }

        delete[] sorted_arr;
        return result;
    }

    //min value element
    int min() {
        if (get_size() == 0) {
            std::cout << "Error 'array is empty'" << std::endl;
            return 0;
        }

        int min_val = get(0);
        for (int i = 1; i < get_size(); i++) {
            if (get(i) < min_val) {
                min_val = get(i);
            }
        }
        return min_val;
    }

    //max value element
    int max() {
        if (get_size() == 0) {
            std::cout << "Error 'array is empty'" << std::endl;
            return 0;
        }

        int max_val = get(0);
        for (int i = 1; i < get_size(); i++) {
            if (get(i) > max_val) {
                max_val = get(i);
            }
        }
        return max_val;
    }
};
