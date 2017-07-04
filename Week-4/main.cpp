#include "hwlib.hpp"

void sequence( hwlib::pin_out & p1, hwlib::pin_out & p2, hwlib::pin_out & p3, hwlib::pin_out & p4){
	for(;;){
		p1.set(1);
		p2.set(1);
		p3.set(0);
		p3.set(0);
		
		hwlib::wait_ms(500);
		
		p1.set(0);
		p2.set(1);
		p3.set(1);
		p4.set(0);
		
		hwlib::wait_ms(500);
		
		p1.set(0);
		p2.set(0);
		p3.set(1);
		p4.set(1);
		
		hwlib::wait_ms(500);
		
		p1.set(0);
		p2.set(1);
		p3.set(1);
		p4.set(0);
		
		hwlib::wait_ms(500);
		
		p1.set(1);
		p2.set(1);
		p3.set(0);
		p4.set(0);
	}
}

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto led0 = target::pin_out( target::pins::d7 );
	auto led1 = target::pin_out( target::pins::d6 );
	auto led2 = target::pin_out( target::pins::d5 );
	auto led3 = target::pin_out( target::pins::d4 );
	
	sequence( led0, led1, led2, led3 );
	
}