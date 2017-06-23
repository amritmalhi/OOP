#include "ostream"
#include "vector.hpp"
#include "rational.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

// Vector ADT tests
TEST_CASE("Default constructor") {
    vector v;
    std::stringstream s;
    s << v;
    REQUIRE(s.str() == "(0,0)");
}

TEST_CASE ("Constructor") {
    vector v (6, 5);
    std::stringstream s;
    s << v;
    REQUIRE (s.str() == "(6,5)"); 
}

TEST_CASE ("Monadic addition") {
    vector a (1, 2), b (3, 4), c;
    a = + b;
    c = + a;
    REQUIRE (a == vector (3, 4));
    REQUIRE (c == vector (3, 4));
}

TEST_CASE ("Diadic addition") {
    vector a (1, 2), b (3, 4);
    vector c = a + b;
    REQUIRE (c == vector (4,6));
}

TEST_CASE ("+= operator") {
    vector a ( 1, 2 );
    vector b = ( a += vector ( 1, 4 )); 
    REQUIRE ( a == vector ( 2, 6 ) );     
    REQUIRE ( b == vector ( 2, 6 ) ); 
}

TEST_CASE ("*= operator") {
    vector a( 8, 4 );
	a *= 3;
	REQUIRE( a == vector( 24, 20 ));
}

TEST_CASE ("Multiply int by vector") {
    vector a (3, 8);
    a = 5 * a;
    REQUIRE (a == vector( 15, 40 ));
}

TEST_CASE ("Multiply vector by int") {
    vector a (9, 10);
    a = a * 5;
    REQUIRE (a == vector( 45, 50 ));
}

/**
// Rational ADT tests
TEST_CASE( "constructor, two_parameters" ){
   rational v( 3, 4 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "(0x3/0x4)" );   
}

TEST_CASE( "equality, equal" ){
   rational v( 1, 2 );
   REQUIRE( v == rational( 1, 2 ) ); 
}

TEST_CASE( "equality, unequal" ){
   rational v( 1, 2 );
   REQUIRE( v == rational(1,6) ); 
}

TEST_CASE( "constructor, two_parameters; reduction" ){
   rational v( 10, 2 );
   REQUIRE( v == rational( 10, 2 ) ); 
}

TEST_CASE( "constructor, one parameter" ){
   rational v( 6 );
   REQUIRE( v == rational( 6, 1 ) );   
}

TEST_CASE( "multiply by integer" ){
   rational v( 3, 4 );
   rational x = v * 7;
   REQUIRE( v == rational( 3, 4 ) );   
   REQUIRE( x == rational( 21, 4 ) );   
}

TEST_CASE( "multiply by integer; reduction" ){
   rational v( 3, 10 );
   rational x = v * 5;
   REQUIRE( v == rational( 3, 10 ) );   
   REQUIRE( x == rational( 15, 20 ) );   
}

TEST_CASE( "multiply by rational" ){
   rational v( 3, 4 );
   rational x = v * rational( 9, 7 );
   REQUIRE( v == rational( 3, 4 ) );   
   REQUIRE( x == rational( 27, 28 ) );   
}

TEST_CASE( "multiply by rational; reduction" ){
   rational v( 3, 10 );
   rational x = v * rational( 4, 6 );
   REQUIRE( v == rational( 3, 10 ) );   
   REQUIRE( x == rational( 12, 60 ) );   
}

TEST_CASE( "add rational into rational" ){
   rational v( 3, 10 );
   v += rational( 6, 7 ); 
   REQUIRE( v == rational( 81, 70 ) );     
}

TEST_CASE( "add rational into rational; reduction" ){
   rational v( 23, 147 );
   v += rational( 5, 91 ); 
   REQUIRE( v == rational( 404, 1911));     
}

TEST_CASE( "add rational into rational; return value" ){
   rational v( 1, 2 );
   rational x = ( v += rational( 1, 4 )); 
   REQUIRE( v == rational( 3, 4 ) );     
   REQUIRE( x == rational( 3, 4 ) );     
}

TEST_CASE( "multiply rational into rational" ){
   rational v( 3, 10 );
   v *= rational( 1, 2 ); 
   REQUIRE( v == rational( 3, 20 ) );     
}

TEST_CASE( "multiply rational into rational; reduction" ){
   rational v( 2, 3 );
   v *= rational( 3, 2 ); 
   REQUIRE( v == rational( 1, 1 ) );     
}

TEST_CASE( "multiply rational into rational; return value" ){
   rational v( 3, 10 );
   rational x = ( v *= rational( 1, 2 )); 
   REQUIRE( x == rational( 3, 20 ) );     
}
**/









