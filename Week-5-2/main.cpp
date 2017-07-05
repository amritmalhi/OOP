#include "hwlib.hpp"
#include "pin_in_two.hpp"

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto led0 = target::pin_out( target::pins::d22 );
	
	auto sw0 = target::pin_in( target::pins::d24 );
	auto sw1 = target::pin_in( target::pins::d26 );
	auto pins = pin_in_two( sw0, sw1 );
	
	for( ;; ){
		led0.set( pins.get() );
	}
	
	return 0;
}