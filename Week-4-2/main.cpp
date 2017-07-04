#include "hwlib.hpp"

void counter ( hwlib::pin_out & led0, hwlib::pin_out & led1, hwlib::pin_out & led2, hwlib::pin_out & led3, auto more, auto less ){
	int counter = 0;
	for (;;) {
	if (more.get() == 0 && counter <= 4) {
		counter++;
	} 
	
	if (less.get() == 0 && counter != 0) {
		counter--;
	}
	
	if (counter == 0) {
		led0.set(0);
		led1.set(0);
		led2.set(0);
		led3.set(0);
	} else if (counter == 1) {
		led0.set(1);
		led1.set(0);
		led2.set(0);
		led3.set(0);
	} else if (counter == 2) {
		led0.set(1);
		led1.set(1);
		led2.set(0);
		led3.set(0);
	} else if (counter == 3) {
		led0.set(1);
		led1.set(1);
		led2.set(1);
		led3.set(0);
	} else if (counter == 4) {
		led0.set(1);
		led1.set(1);
		led2.set(1);
		led3.set(1);
	}
	hwlib::wait_ms(150);
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
	
	auto sw0 = target::pin_in( target::pins::d13 );
	auto sw1 = target::pin_in( target::pins::d12 );
	
	counter( p0, p1, p2, p3, sw0, sw1 );
	
	return 0;
}