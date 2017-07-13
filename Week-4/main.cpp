#include "hwlib.hpp"

void sequence ( auto & leds, int ms = 150) {
	for (;;) {
		for (unsigned int i = 0; i < leds.number_of_pins() - 1; i++) {
			leds.set(0x03 << i);
			hwlib::wait_ms(ms);
		}
		for (unsigned int i = leds.number_of_pins() - 2; i > 0; i--) {
			leds.set(0x03 << i);
			hwlib::wait_ms(ms);
		}
	}
}

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto led0 = target::pin_out( target::pins::d3 );
	auto led1 = target::pin_out( target::pins::d4 );
	auto led2 = target::pin_out( target::pins::d5 );
	auto led3 = target::pin_out( target::pins::d6 );
	auto led4 = target::pin_out( target::pins::d7 );
	
	auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3, led4 );
    ::sequence( leds );
	
}