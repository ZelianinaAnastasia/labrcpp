#include <iostream>
#include "ExtendedDynamicIntArray.cpp"

int main() {
    std::cout << "Task #4. Inheritance" << std::endl;

    //array making
    ExtendedDynamicIntArray arr(5);
    arr.set(0, 10);
    arr.set(1, -20);
    arr.set(2, 50);
    arr.set(3, 30);
    arr.set(4, -5);

    std::cout << "Array: ";
    arr.print();

    //inherited method tests
    std::cout << "\n1. Mean value : " << arr.average() << std::endl;
    std::cout << "2. Median value: " << arr.median() << std::endl;
    std::cout << "3. Min value element: " << arr.min() << std::endl;
    std::cout << "4. Max value element: " << arr.max() << std::endl;

    // Тест с пустым массивом
    std::cout << "\n5. Singleton array test:" << std::endl;
    ExtendedDynamicIntArray arr2(1);
    arr2.set(0, 42);
    std::cout << "Array: ";
    arr2.print();
    std::cout << "Mean: " << arr2.average() << std::endl;
    std::cout << "Median: " << arr2.median() << std::endl;

    // Тест с четным количеством элементов
    std::cout << "\n6. Test with even quantity of elements:" << std::endl;
    ExtendedDynamicIntArray arr3(4);
    arr3.set(0, 1);
    arr3.set(1, 3);
    arr3.set(2, 2);
    arr3.set(3, 4);
    std::cout << "Array: ";
    arr3.print();
    std::cout << "Median: " << arr3.median() << std::endl;

    // Тест с отрицательными значениями
    std::cout << "\n7. Test with negative elements:" << std::endl;
    ExtendedDynamicIntArray arr4(3);
    arr4.set(0, -10);
    arr4.set(1, -30);
    arr4.set(2, -20);
    std::cout << "Array: ";
    arr4.print();
    std::cout << "Min: " << arr4.min() << std::endl;
    std::cout << "Max: " << arr4.max() << std::endl;
    std::cout << "Mean: " << arr4.average() << std::endl;

    return 0;
}
