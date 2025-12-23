#include <iostream>
#include "func.h"
#include "structs.h"

#pragma once

int main() {
	std::cout << "Task #1. Structs" << std::endl;

	Point p1;
	set_point(p1);
	get_point(p1);

	Circle cir1;
	set_circle(cir1);
	get_circle(cir1);
	Circle cir2;
	set_circle(cir2);
	get_circle(cir2);

	Square sq1;
	set_square(sq1);
	get_square(sq1);
	Square sq2;
	set_square(sq2);
	get_square(sq2);

	std::cout << "All coordinates printed second in one figure" << " " <<
		"will be used in functions where figures are using two times" << std::endl;

	std::cout << std::boolalpha;

	std::cout << "Circumference is " << circle_leng(cir1) << std::endl;
	std::cout << "Area of the circle is " << circle_space(cir1) << std::endl;
	std::cout << "Perimeter is " << square_leng(sq1) << std::endl;
	std::cout << "Area of the square is " << square_space(sq1) << std::endl;
	
	std::cout << "Point is in circle is " << (bool)point_in_circle(p1, cir1) << std::endl;
	std::cout << "Point is on circle's contour is " << (bool)point_on_circle(p1, cir1) << std::endl;

	std::cout << "Point is in square is " << (bool)point_in_square(p1, sq1) << std::endl;
	std::cout << "Point is on square's contour is " << (bool)point_on_square(p1, sq1) << std::endl;


	std::cout << "Circle intersects circle is " << (bool)circle_witn_circle(cir1, cir2) << std::endl;
	std::cout << "Square intersects square is " << (bool)square_with_square(sq1, sq2) << std::endl;
	std::cout << "Circle and square intersecting is " << (bool)circle_with_square(cir1, sq2) << std::endl;


	std::cout << "Circle is in circle is " << (bool)circle_in_circle(cir1, cir2) << std::endl;
	std::cout << "Square is in square is " << (bool)square_in_square(sq1, sq2) << std::endl;
	std::cout << "Square is in square is " << (bool)square_in_circle(cir1, sq1) << std::endl;
	std::cout << "Circle is in square is " << (bool)circle_in_square(cir1, sq1) << std::endl;

}