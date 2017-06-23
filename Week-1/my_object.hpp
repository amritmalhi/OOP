#ifndef MY_OBJECT_HPP
#define MY_OBJECT_HPP

#include "window.hpp"
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"

class my_object {
private:
	window & w;
	filled_rectangle fr;
	rectangle r;
	line l1, l2, l3, l4;
	circle c1, c2;
	bool withUnderscore;
public:
	my_object(window & w, bool withUnderscore);
	draw();
};

#endif