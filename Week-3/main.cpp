#include "window.hpp"
#include "wall.hpp"
#include "ball.hpp"
#include "line.hpp"

int main(){
	bool filled = true;
	int updateInterval = 200;
	window w( vector( 128, 64 ), 2 );
	// Linker en rechter walls nemen default waarde aan voor update_interval, top en bottom walls nemen de updateInterval als parameter aan.
	// Walls beginnen filled.
	wall top( w, vector(   0,  0 ), vector( 127,  4 ), filled, updateInterval);
	wall right( w, vector( 123,  0 ), vector( 127, 63 ), filled);
	wall bottom( w, vector(   0, 59 ), vector( 127, 63 ), filled, updateInterval);
	wall left( w, vector(   0,  0 ), vector(   4, 63 ), filled);
	ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   
	drawable * objects[] = { &b, &top, &left, &right, &bottom };

	for(;;){
		w.clear();
		for( auto & p : objects ){
			p->draw();
		}
		wait_ms( 200 );
		for( auto & p : objects ){
			p->update();
		}
		for( auto & p : objects ){
			for( auto & other : objects ){
				p->interact( *other );
			} 
		}
	}
}

