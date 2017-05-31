// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

#include "filled_rectangle.hpp"
#include "my_object.hpp"

int main(int argc, char **argv){
   window w( 128, 64, 2);
   
   
   //line diagonal_line( w, 5, 5, 30, 40 );
   //diagonal_line.print();
   
   //rectangle box( w, 10, 5, 100, 60 );
   //box.print();
   
   //circle ball( w, 70, 30, 20 );
   //ball.print();
   
   //filled_rectangle doos(w, 50, 5, 100, 60);
   //doos.draw();
   
   my_object mo(w, false);
   mo.draw();
   
   return 0;
}
