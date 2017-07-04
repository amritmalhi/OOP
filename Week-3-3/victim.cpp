#include "victim.hpp"

victim::victim( window & w, const vector & start, const vector & end ):
	rectangle( w, start, end )
{}

void victim::interact( drawable & other ) {
	if( this != & other) {
		if( overlaps( other ) ) {
			contact = true;
		}
	}
}

void victim::update () {
	
	if ( location.x == end.x || location.y == end.y ){
		*this = victim( w, vector( 0, 0 ), vector( 0, 0 ) );
	}
	
	if ( contact ) {
		if ( location.x <= end.x ) {
			*this = victim( w, location += vector( 1, 0 ), end += vector( -1, 0 ));
		}
		if ( location.y <= end.y ) {
			*this = victim( w, location += vector( 0, 1 ), end += vector( 0, -1 ));
		}
	}
}