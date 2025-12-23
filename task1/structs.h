#pragma once

struct Point {
	float kx; //point's x coordinate
	float ky; //point's y coordinate
};

struct Circle {
	Point central; 
	float rad_leng; //radius length
};

struct Square {
	Point left_up; //square's top left point
	float side_leng; //square's side length
};



