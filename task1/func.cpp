#include <iostream>
#define _USE_MATH_DEFINE
#include <cmath>
#include "structs.h"
#include "func.h"
#pragma once

#define M_PI 3.1415926 //pi const
#define eps 1e-5 //eps precision

//helper function for number and precision eps comparison
int equal(double a, double b) {
	return fabs(a - b) < eps;
}

//helper function for distance calculating
double calc_distance(Point& p1, Point& p2) {
	return sqrt(pow((p1.kx - p2.kx), 2) + pow((p1.ky - p2.ky), 2));
}

void set_point(Point& k) {
	std::cout << "Share imagined value of point's (x, y) coordinates" 
		<< std::endl;
	std::cin >> k.kx >> k.ky;
}
void get_point(Point& k){
	std::cout << "Point's coordinates you've typed are" << std::endl;
	std::cout << k.kx << " " << k.ky << std::endl;
}

void set_circle(Circle& c) {
	std::cout << "Share imagined value of central's (x, y) coordinates"
		<< std::endl;
	std::cin >> c.central.kx >> c.central.ky;
	std::cout << "Share imagined value of circle's radius" << std::endl;
	std::cin >> c.rad_leng;
}
void get_circle(Circle& c){
	std::cout << "Central's coordinates and radius you've typed are" << std::endl;
	std::cout << c.central.kx << " " << c.central.ky 
		<< " " << c.rad_leng << std::endl;
}

void set_square(Square& s) {
	std::cout << "Share imagined value of upper left point's (x, y) coordinates"
		<< std::endl;
	std::cin >> s.left_up.kx >> s.left_up.ky;
	std::cout << "Share imagined value of square's side length" << std::endl;
	std::cin >> s.side_leng;
}
void get_square(Square& s){
	std::cout << "Upper left point's coordinates and side's length you've typed are"
		<< std::endl;
	std::cout << s.left_up.kx << " " << s.left_up.ky << " " << s.side_leng << std::endl;
}


double circle_leng(Circle& c){
	return 2 * M_PI * c.rad_leng;
}
double circle_space(Circle& c){
	return pow(c.rad_leng, 2) * M_PI;
}

double square_leng(Square& s){
	return 4 * s.side_leng;
}
double square_space(Square& s){
	return pow(s.side_leng, 2);
}


double point_in_circle(Point& k, Circle& c) { 
	double dist = calc_distance(k, c.central);
	return dist < c.rad_leng - eps;
}

double point_on_circle(Point& k, Circle& c) { 
	double dist = calc_distance(k, c.central);
	return equal(c.rad_leng, dist);
}

double point_in_square(Point& k, Square& s){
	double ang1_kx = s.left_up.kx;
	double ang1_ky = s.left_up.ky;
	double ang2_kx = s.left_up.kx + s.side_leng;
	double ang2_ky = s.left_up.ky - s.side_leng;

	return (k.kx > ang1_kx + eps) && (k.ky < ang1_ky - eps) 
		&& (k.kx < ang2_kx - eps) && (k.ky > ang2_ky + eps);
}


double point_on_square(Point& k, Square& s) {
	double ang1_kx = s.left_up.kx;
	double ang1_ky = s.left_up.ky;
	double ang2_kx = s.left_up.kx + s.side_leng;
	double ang2_ky = s.left_up.ky - s.side_leng;

	return equal(k.kx, ang1_kx) || equal(k.ky, ang1_ky)
		|| equal(k.kx, ang2_kx) || equal(k.ky, ang2_ky);
}


double circle_witn_circle(Circle& c1, Circle& c2) {
	double sumrad = c1.rad_leng + c2.rad_leng;
	double dist = calc_distance(c1.central, c2.central);
	return dist <= sumrad - eps;
}

double square_with_square(Square& s1, Square& s2) { 
	Point leftup;
	leftup.kx = s2.left_up.kx;
	leftup.ky = s2.left_up.ky;
	Point rightup;
	rightup.kx = s2.left_up.kx + s2.side_leng;
	rightup.ky = s2.left_up.ky;
	Point leftdown;
	leftdown.kx = s2.left_up.kx;
	rightup.ky = s2.left_up.ky - s2.side_leng;
	Point rightdown;
	rightdown.kx = s2.left_up.kx + s2.side_leng;
	rightdown.ky = s2.left_up.ky - s2.side_leng;

	return (point_in_square(leftup, s1) || point_in_square(rightup, s1)
		|| point_in_square(leftdown, s1) || point_in_square(rightdown, s1));
}

double circle_with_square(Circle& c, Square& s){ 
	Point left;
	left.kx = c.central.kx - c.rad_leng;
	left.ky = c.central.ky;
	Point right;
	right.kx = c.central.kx + c.rad_leng;
	right.ky = c.central.ky;
	Point up;
	up.kx = c.central.kx;
	up.ky = c.central.ky + c.rad_leng;
	Point down;
	down.kx = c.central.kx;
	down.ky = c.central.ky - c.rad_leng;

	Point leftup;
	leftup.kx = s.left_up.kx;
	leftup.ky = s.left_up.ky;
	Point rightup;
	rightup.kx = s.left_up.kx + s.side_leng;
	rightup.ky = s.left_up.ky;
	Point leftdown;
	leftdown.kx = s.left_up.kx;
	rightup.ky = s.left_up.ky - s.side_leng;
	Point rightdown;
	rightdown.kx = s.left_up.kx + s.side_leng;
	rightdown.ky = s.left_up.ky - s.side_leng;


	return (point_in_square(left, s) || point_in_square(right, s)
		|| point_in_square(up, s) || point_in_square(down, s)
		|| point_in_circle(leftup, c) || point_in_circle(rightup, c)
		|| point_in_circle(leftdown, c) || point_in_circle(rightdown, c));
}


double circle_in_circle(Circle& c1, Circle& c2) {
	Point left;
	left.kx = c2.central.kx - c2.rad_leng;
	left.ky = c2.central.ky;
	Point right;
	right.kx = c2.central.kx + c2.rad_leng;
	right.ky = c2.central.ky;
	Point up;
	up.kx = c2.central.kx;
	up.ky = c2.central.ky + c2.rad_leng;
	Point down;
	down.kx = c2.central.kx;
	down.ky = c2.central.ky - c2.rad_leng;

	return (point_in_circle(left, c1) || point_in_circle(right, c1)
		|| point_in_circle(down, c1) || point_in_circle(up, c1));
}

double square_in_square(Square& s1, Square& s2) {
	Point leftup;
	leftup.kx = s2.left_up.kx;
	leftup.ky = s2.left_up.ky;
	Point rightup;
	rightup.kx = s2.left_up.kx + s2.side_leng;
	rightup.ky = s2.left_up.ky;
	Point leftdown;
	leftdown.kx = s2.left_up.kx;
	rightup.ky = s2.left_up.ky - s2.side_leng;
	Point rightdown;
	rightdown.kx = s2.left_up.kx + s2.side_leng;
	rightdown.ky = s2.left_up.ky - s2.side_leng;


	return (point_in_square(leftup, s1) || point_in_square(rightup, s1)
		|| point_in_square(leftdown, s1) || point_in_square(rightdown, s1));
}

double square_in_circle(Circle& c, Square& s) {
	Point leftup;
	leftup.kx = s.left_up.kx;
	leftup.ky = s.left_up.ky;
	Point rightup;
	rightup.kx = s.left_up.kx + s.side_leng;
	rightup.ky = s.left_up.ky;
	Point leftdown;
	leftdown.kx = s.left_up.kx;
	rightup.ky = s.left_up.ky - s.side_leng;
	Point rightdown;
	rightdown.kx = s.left_up.kx + s.side_leng;
	rightdown.ky = s.left_up.ky - s.side_leng;


	return(point_in_circle(leftup, c) || point_in_circle(rightup, c)
		|| point_in_circle(leftdown, c) || point_in_circle(rightdown, c));
}

double circle_in_square(Circle& c, Square& s) {
	Point left;
	left.kx = c.central.kx - c.rad_leng;
	left.ky = c.central.ky;
	Point right;
	right.kx = c.central.kx + c.rad_leng;
	right.ky = c.central.ky;
	Point up;
	up.kx = c.central.kx;
	up.ky = c.central.ky + c.rad_leng;
	Point down;
	down.kx = c.central.kx;
	down.ky = c.central.ky - c.rad_leng;

	return (point_in_square(left, s) || point_in_square(right, s)
		|| point_in_square(up, s) || point_in_square(down, s));
}