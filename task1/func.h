#include "structs.h"
#pragma once

//helper function for number and precision eps comparison
int equal(double a, double b);

//helper function for distance calculating
double calc_distance(Point& p1, Point& p2);

//for values from input
void set_point(Point& k);
void get_point(Point& k);

void set_circle(Circle& c);
void get_circle(Circle& c);

void set_square(Square& s);
void get_square(Square& s);


double circle_leng(Circle& c);
double circle_space(Circle& c);

double square_leng(Square& s);
double square_space(Square& s);


double point_in_circle(Point& k, Circle& c);
double point_on_circle(Point& k, Circle& c);

double point_in_square(Point& k, Square& s);
double point_on_square(Point& k, Square& s);


//intersection
double circle_witn_circle(Circle& c1, Circle& c2);
double square_with_square(Square& s1, Square& s2);
double circle_with_square(Circle& c, Square& s);

//inside checking
double circle_in_circle(Circle& c1, Circle& c2);
double square_in_square(Square& s1, Square& s2);
double square_in_circle(Circle& c, Square& s);
double circle_in_square(Circle& c, Square& s);