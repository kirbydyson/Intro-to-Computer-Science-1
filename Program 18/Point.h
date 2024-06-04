#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <cmath>

using namespace std;

struct Point{
   double x,y;

   Point(const Point& p){
       *this = p;
   }

   Point(double x = 0, double y = 0){
      this->x = x;
      this->y = y;
   }

   Point& operator= (const Point& p){
       x = p.x;
       y = p.y;
   }

   double distance(Point p){
       return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
   }
};

#endif // POINT_H_INCLUDED
