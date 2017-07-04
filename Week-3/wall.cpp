#include "wall.hpp"

wall::wall( window & w, const vector & start, const vector & end, const bool & filled, const int & update_interval):
	rectangle(w, start, end),
	filled ( filled ),
	update_interval ( update_interval )
{}
	
void wall::draw() {
	if ( filled ) {
		for (int y = location.y; y < end.y; y++) {
			for (int x = location.x; x < end.x; x++) {
				w.draw(vector(x, y));
			}
		}
	} else {
		rectangle::draw();
	}
}

void wall::update() {
	if ( update_count * 100 >= update_interval ) {
		update_count = 0;
		filled = !filled;
	} else {
		update_count++;
	}
}