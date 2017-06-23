#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

/// @file

/// \brief
/// Vector ADT
/// \details
/// This is an ADT that implements a vector that stores the x- and y-values
class vector {
private:
    int x;
    int y;
public:

   /// \brief
   /// constructor from explicit values
   /// \details
   /// This constructor initializes a vector from its x and y value.
   vector ( ):
     x ( 0 ), y ( 0 )
   {}

    /// \brief
    /// default constructor
    /// \details
    /// This constructor initializes a vector with 0 as default value for x and y.
    vector ( int x, int y ):
        x ( x ), y ( y )
    {}
    
    /// \brief
    /// output operator for a vector
    /// \details
    /// This operator<< prints a constructor in the format
    /// (x,y) where both values are printed as
    /// decimal values.
    friend std::ostream & operator<<( std::ostream & lhs, const vector & v ){
         lhs << "(" << v.x << "," << v.y << ")";
         return lhs;
    }   
        
    /// \brief   
    /// compare two vectors
    /// \details
    /// This operator tests for equality. It returns true
    /// if and only if the x and y of both
    /// operands are equal.
    bool operator== ( const vector & rhs ) const {
        return ( x == rhs.x ) || ( y == rhs.y );
    }
    
    /// \brief   
    /// Monadic addition
    /// \details
    /// ??
    vector operator+ ( ) const {
        return vector( x, y );
    }
    
    /// \brief   
    /// add the x and y values of a vector to this vector
    /// \details
    /// This operator+ adds the x and y values from the parameter vector to the current vector.
    vector operator+ ( const vector v ) const {
        return vector ( x + v.x, y + v.y);
    }
    
    /// \brief   
    /// add a vector to a vector
    /// \details
    /// This operator+= adds a vector to a vector
    vector operator+= ( const vector & rhs ) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    
    /// \brief
	/// multiply vector by integer and assign to vector
	/// \details
	/// This operator*= multiplies a vector by an integer and assigns
	/// to the vector.
    vector & operator*= ( const int rhs ) {
        x *= rhs;
        y *= rhs;
        return *this;
    }
};

/// \brief
/// multiply vector by integer
/// \details
/// This operator* multiplies a vector by an integer.
vector operator* ( vector lhs, const int rhs ) {
        return lhs *= rhs;
}

/// \brief
/// multiply integer by vector
/// \details
/// This operator* multiplies an integer by a vector.    
vector operator* ( const int lhs, vector rhs ) {
        return rhs *= lhs;
}

#endif // VECTOR_HPP