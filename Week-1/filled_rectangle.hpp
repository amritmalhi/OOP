#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"

class filled_rectangle {
private:
	window & w;
	int p_start_x, p_start_y, p_end_x, p_end_y;
public:
	filled_rectangle(window & w, int p_start_x, int p_start_y, int p_end_x, int p_end_y);
	void draw();
};

#endif