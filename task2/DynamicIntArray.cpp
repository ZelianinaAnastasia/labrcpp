#include <iostream>
#include "DynamicIntArray.h"

//constructor
DynamicIntArray:: DynamicIntArray(int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;  
        }
    }

//destructor
DynamicIntArray::~DynamicIntArray() {
    delete[] arr;
}

//copying constructor 
DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) {
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

//outputting array
void DynamicIntArray::print() {
    for (int i = 0; i < size; i++) {
       std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//getter
int DynamicIntArray::get(int index) {
    if (index < 0 || index >= size) {
       std::cout << "Ошибка: неверный индекс!" << std::endl;
       return 0;
    }
    return arr[index];
}

//setter
void DynamicIntArray::set(int index, int value) {
    if (index < 0 || index >= size) {
       std::cout << "Ошибка: неверный индекс!" << std::endl;
       return;
    }
    if (value < -100 || value > 100) {
        std::cout << "Ошибка: значение должно быть от -100 до 100!" << std::endl;
        return;
    }
    arr[index] = value;
}

//end adding
void DynamicIntArray::push_back(int value) {
   if (value < -100 || value > 100) {
       std::cout << "Ошибка: значение должно быть от -100 до 100!" << std::endl;
       return;
   }

    int* new_arr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        new_arr[i] = arr[i];
    }

    new_arr[size] = value;

    delete[] arr;

    arr = new_arr;
    size++;
    }

//array sum
void DynamicIntArray::add(DynamicIntArray& other) {
    for (int i = 0; i < size; i++) {
       if (i < other.size) {
           arr[i] += other.arr[i];
       }
        if (arr[i] > 100) arr[i] = 100;
        if (arr[i] < -100) arr[i] = -100;
    }
}

//array substraction
void DynamicIntArray::subtract(DynamicIntArray& other) {
    for (int i = 0; i < size; i++) {
       if (i < other.size) {
            arr[i] -= other.arr[i];
       }
        if (arr[i] > 100) arr[i] = 100;
        if (arr[i] < -100) arr[i] = -100;
    }
}

//size get
int DynamicIntArray::get_size() {
    return size;
}