#include "hwlib.hpp"
#include "pin_out_all.hpp"
#include "pin_out_invert.hpp"

int main( void ){
	// kill the watchdog
	WDT->WDT_MR = WDT_MR_WDDIS;
	
	namespace target = hwlib::target;
	
	auto ds = target::pin_out( target::pins::d8 );
	auto shcp = target::pin_out( target::pins::d9 );
	auto stcp = target::pin_out( target::pins::d10 );
	
	auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
		shcp, ds, hwlib::pin_in_dummy
	);
	
	auto hc595 = hwlib::hc595( spi, stcp );
	
	auto led0 = target::pin_out( target::pins::d2 );
	auto led1 = target::pin_out( target::pins::d3 );
	auto led2 = target::pin_out( target::pins::d4 );
	auto led3 = target::pin_out( target::pins::d5 );
	
	auto leds = pin_out_all(
		led0,
		led1,
		led2,
		led3
	);
	
	auto leds_inverted = pin_out_invert( leds );
	
	auto leds0 = pin_out_all(
		leds_inverted,
		hc595.p0,
		hc595.p1,
		hc595.p2,
		hc595.p3
	);
	
	hwlib::blink( leds0 );
	
	return 0;
}