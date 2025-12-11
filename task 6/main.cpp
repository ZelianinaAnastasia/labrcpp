#include <iostream>
#include "DynamicIntArray.h"


int main() {
        std::cout << "Task #2. Classes" << std::endl;

        std::cout << "\n1)Creating array of three elements:" << std::endl;
        DynamicIntArray a(3);
        a.set(0, 10);
        a.set(1, -20);
        a.set(2, 50);

        try {
            a.set(3, 30);
        } catch (const std::out_of_range& e) {
            std::cout << "Catched exception: " << e.what() << std::endl;
        }
        
        try {
            a.set(1, 150);
        } catch (const std::invalid_argument& e) {
            std::cout << "Catched exception: " << e.what() << std::endl;
        }
        

        std::cout << "Array a: ";
        a.print();

        std::cout << "a[1] = " << a.get(1) << std::endl;

        try {
            std::cout << "a[5] = " << a.get(5) << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Catched exception: " << e.what() << std::endl;
        }

        std::cout << "\n2)Copying array:" << std::endl;
        DynamicIntArray b = a;
        std::cout << "Array b (copy a): ";
        b.print();

        std::cout << "\n3)Adding elements to the end:" << std::endl;
        a.push_back(75);

        try {
            a.push_back(-101);
        } catch (const std::invalid_argument& e) {
            std::cout << "Catched exception: " << e.what() << std::endl;
        }

        std::cout << "Array a after push_back: ";
        a.print();

        std::cout << "\n4)Summ and substract:" << std::endl;

        DynamicIntArray c(3);
        c.set(0, 5);
        c.set(1, 10);
        c.set(2, 15);

        DynamicIntArray d(2);
        d.set(0, 3);
        d.set(1, -5);

        std::cout << "Array c: ";
        c.print();
        std::cout << "Array d: ";
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