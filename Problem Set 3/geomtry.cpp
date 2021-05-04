#include "geomtry.hpp"
#include <iostream>

PointArray::PointArray(){
    size = 0;
    points = new Point [0];
}

PointArray :: PointArray ( const Point ptsToCopy [], const int toCopySize) {
    size = toCopySize ;
    points = new Point [ toCopySize ];
    for(int i = 0; i < toCopySize ; ++i) {
        points [i] = ptsToCopy [i];
    }
 }

 PointArray :: PointArray ( const PointArray & other ) {

     size = other . size ;
     points = new Point [ size ];
     for (int i = 0; i < size ; i++) {
         points [i] = other.points [i];
     }
 }

 PointArray ::~ PointArray () {
     delete [] points ;
 }

 void PointArray :: resize ( int newSize ) {
     Point *pts = new Point [ newSize ];
     int minSize = ( newSize > size ? size : newSize );
     for (int i = 0; i < minSize ; i++){
         pts[i] = points [i];
     }
     delete [] points ;
     size = newSize ;
     points = pts ;
 }
  

void PointArray :: clear () {
 resize (0) ;
 }


 void PointArray :: push_back ( const Point &p) {
 resize ( size + 1);
 points [ size - 1] = p;
 // Could also just use insert (size , p);
 }

 void PointArray :: insert ( const int pos , const Point &p) {
 resize ( size + 1);

 for (int i = size - 1; i > pos; i --) {
 points [i] = points [i -1]; }

 points [pos ] = p;
 }

 void PointArray :: remove ( const int pos ) {
 if( pos >= 0 && pos < size ) {
 for(int i = pos; i < size - 2; i++) {
 points [i] = points [i + 1];
 }
 resize ( size - 1);
 }
 }

 Point * PointArray :: get( const int pos) {
 return pos >= 0 && pos < size ? points + pos : 0 ;
 }

 const Point * PointArray :: get( const int pos) const {
 return pos >= 0 && pos < size ? points + pos : 0 ;
 }
   
     
//Part 5
int Polygon::numPolygons = 0;

Polygon :: Polygon ( const PointArray &pa) : points (pa) {
++ numPolygons ;
}

Polygon :: Polygon ( const Point pointArr [], const int numPoints ) :
points ( pointArr , numPoints ) {
++ numPolygons ;
}

//Given code
     Point constructorPoints [4];
     
     Point * updateConstructorPoints ( const Point &p1 , const Point &p2 , const Point &p3, const Point &p4 = Point (0 ,0)) {
         constructorPoints [0] = p1;
         constructorPoints [1] = p2;
         constructorPoints [2] = p3;
         constructorPoints [3] = p4;
         return constructorPoints ;
     }
     
     
     Rectangle :: Rectangle ( const Point &ll , const Point &ur) : Polygon (updateConstructorPoints (ll , Point (ll.getX() , ur.getY()), ur , Point (ur.getX() , ll.getY())), 4) {}
    
      Rectangle :: Rectangle ( const int llx , const int lly , const int urx , const int ury): Polygon ( updateConstructorPoints ( Point (llx , lly), Point (llx , ury),Point (urx , ury), Point (urx ,lly)), 4) {}
     
      double Rectangle :: area () const {
      int length = points.get(1)->getY() - points.get(0)->getY();
      int width = points.get(2)->getX() - points.get(1)->getX();
      return std :: abs (( double ) length * width );
      }



