#ifndef PIN_OUT_INVERT_HPP
#define PIN_OUT_INVERT_HPP
#include "hwlib.hpp"

class pin_out_invert : public hwlib::pin_out {
private:
	
	hwlib::pin_out * pin;
	
public:
	
	pin_out_invert( auto & pin ):
		pin( &pin )
	{}
	
	void set( bool x, hwlib::buffering buf = hwlib::buffering::unbuffered ) override {
		pin->set( ! x );
	}

};

#endif // PIN_OUT_INVERT_HPP
