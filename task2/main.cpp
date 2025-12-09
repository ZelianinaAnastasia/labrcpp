#include <iostream>
#include "DynamicIntArray.h"


int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Тестирование DynamicIntArray ===" << std::endl;

    std::cout << "\n1. Создаем массив на 3 элемента:" << std::endl;
    DynamicIntArray a(3);
    a.set(0, 10);
    a.set(1, -20);
    a.set(2, 50);
    a.set(3, 30);  //обработка ошибки неверный индекс
    a.set(1, 150); //обработка ошибки неверное значение

    std::cout << "Массив a: ";
    a.print();

    std::cout << "a[1] = " << a.get(1) << std::endl;
    std::cout << "a[5] = " << a.get(5) << std::endl;  //обработка ошибки

    std::cout << "\n2. Копируем массив:" << std::endl;
    DynamicIntArray b = a;
    std::cout << "Массив b (копия a): ";
    b.print();

    std::cout << "\n3. Добавляем элементы в конец:" << std::endl;
    a.push_back(75);
    a.push_back(-101);  //обработка ошибки
    std::cout << "Массив a после push_back: ";
    a.print();

    std::cout << "\n4. Сложение и вычитание:" << std::endl;

    DynamicIntArray c(3);
    c.set(0, 5);
    c.set(1, 10);
    c.set(2, 15);

    DynamicIntArray d(2);
    d.set(0, 3);
    d.set(1, -5);

    std::cout << "Массив c: ";
    c.print();
    std::cout << "Массив d: ";
    d.print();

    c.add(d);
    std::cout << "c + d = ";
    c.print();

    DynamicIntArray e(3);
    e.set(0, 20);
    e.set(1, 30);
    e.set(2, 40);

    e.subtract(d);
    std::cout << "e - d = ";
    e.print();

    return 0;
}