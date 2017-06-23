#include "my_object.hpp"

my_object::my_object (window & w, bool withUnderscore) :
	w (w),
	fr (w, 80, 50, 110, 53),
	r (w, 5, 5, 122, 60),
	l1 (w, 10, 15, 10, 50), // C
	l2 (w, 10, 15, 35, 15), // C
	l3 (w, 10, 50, 35, 50), // C
	l4 (w, 55, 15, 70, 50), // slash 
	c1 (w, 45, 25, 3),
	c2 (w, 45, 40, 3),
	withUnderscore (withUnderscore)
{} 

my_object::draw () {
	if (withUnderscore == true) {
		fr.draw();
	}
	r.print();
	l1.print();
	l2.print();
	l3.print();
	l4.print();
	c1.print();
	c2.print();
};