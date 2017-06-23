#include "filled_rectangle.hpp"

filled_rectangle::filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
	w (w),
	p_start_x (start_x),
	p_start_y (start_y),
	p_end_x (end_x),
	p_end_y (end_y)
{}

filled_rectangle::draw(){
	int i, j;
	for (i = p_start_x; i < p_end_x; i++) {
		for (j = p_start_y; j < p_end_y; j++) {
			w.draw(i, j);
		}
	}
}
