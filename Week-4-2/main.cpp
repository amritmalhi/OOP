#include "hwlib.hpp"

void sequence (auto & leds, auto & plus, auto & minus, int ms = 200) {
	
	unsigned int pattern = 0x0;
	// Only supports up to 8 leds because of this mask.
	unsigned int mask = 0xFF;
	unsigned int counter = 0;
	
	for (;;) {

		if (!plus.get() && counter < leds.number_of_pins()) {
			counter++;
			
			
		} else if (!minus.get() && counter != 0) {
			counter--;
		}
		
		pattern = mask << (leds.number_of_pins() - counter);
		leds.set(pattern);
		
		hwlib::wait_ms(ms);
	}
	
}

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto p0 = target::pin_out( target::pins::d7 );
	auto p1 = target::pin_out( target::pins::d6 );
	auto p2 = target::pin_out( target::pins::d5 );
	auto p3 = target::pin_out( target::pins::d4 );
	auto p4 = target::pin_out( target::pins::d3 );
	
	auto sw0 = target::pin_in( target::pins::d13 );
	auto sw1 = target::pin_in( target::pins::d12 );
	
	auto leds = hwlib::port_out_from_pins (p0, p1, p2, p3, p4);
	
	::sequence( leds, sw0, sw1 );
	
	return 0;
}