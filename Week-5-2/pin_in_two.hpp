#ifndef PIN_IN_TWO_HPP
#define PIN_IN_TWO_HPP
#include "hwlib.hpp"

class pin_in_two : public hwlib::pin_in {
private:
	hwlib::pin_in & p1;
	hwlib::pin_in & p2;
public:
	pin_in_two( hwlib::pin_in & p1, hwlib::pin_in & p2 ):
		p1( p1 ),
		p2( p2 )
	{}
	
	bool get( hwlib::buffering buf = hwlib::buffering::unbuffered ) override {
		return ( ( ! p1.get() ) && ( ! p2.get() ) );
	}
	
};

#endif // PIN_IN_TWO_HPP
