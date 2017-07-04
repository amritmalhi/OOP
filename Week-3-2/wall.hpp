#ifndef WALL_HPP
#define WALL_HPP

#include "rectangle.hpp"
#include "vector.hpp"
#include "window.hpp"

class wall : public rectangle {
private:
	bool filled;
	int update_interval, update_count = 0;
public:
	wall( window & w, const vector & start, const vector & end, const bool & filled, const int & update_interval, const vector & stuiter = vector (1,1) );
	void draw() override;
	void update() override;
};

#endif // WALL_HPP