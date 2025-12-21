//заголовочный файл со структурами
#pragma once

struct Point {
	float kx; //координата точки по х
	float ky; //координата точки по у
};

struct Circle {
	Point central; //точка центра окружности
	float rad_leng; //длина радиуса
};

struct Square {
	Point left_up; //левая верхняя точка квадрата
	float side_leng; //длина стороны квадрата
};



