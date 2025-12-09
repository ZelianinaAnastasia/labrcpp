#include <iostream>

class DynamicIntArray {
private:
    int* arr;
    int size;

public:
    // Конструктор
    DynamicIntArray(int size);

    // Деструктор
    ~DynamicIntArray();

    // Конструктор копирования
    DynamicIntArray(const DynamicIntArray& other);

    // Вывод массива
    void print();

    // Геттер
    int get(int index);

    // Сеттер
    void set(int index, int value);

    // Добавление в конец
    void push_back(int value);

    // Сложение массивов
    void add(DynamicIntArray& other); 

    // Вычитание массивов
    void subtract(DynamicIntArray& other);

    // Получение размера
    int get_size();
};
