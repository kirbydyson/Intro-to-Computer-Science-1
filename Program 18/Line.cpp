/*
*Author: Kirby Dyson
*Assignment Title: Line Class
*Assignment Description: In this program a Line class will be implemented
that uses two points to represent a line. Thirteen methods will be implemented
using the fields p1 and p2.
*Due Date: 11/11/2022
*Date Created: 11/03/2022
*Date Last Modified: 11/09/2022
*/

#include "Line.h"

Line::Line(Point a, Point b){
    p1 = Point(a);
    p2 = Point(b);
}

void Line::setFirstPoint(const Point& a){
    p1 = a;
}

void Line::setSecondPoint(const Point& a){
    p2 = a;
}

Point Line::getFirstPoint() const{
    return p1;
}

Point Line::getSecondPoint() const{
    return p2;
}

bool Line::hasSlope() const{
    return p1.x != p2.x;
}

double Line::slope() const{
    hasSlope();
    return (p1.y - p2.y) / (p1.x - p2.x);
}

double Line::yIntercept() const{
    hasSlope();
    return p1.y - slope() * p1.x;
}

bool Line::isParallel(const Line& other) const{
    bool flag = false;

    if(hasSlope() && other.hasSlope()) {
        if(slope() == other.slope()) {
            if(yIntercept() != other.yIntercept()) {
                flag = true;
            }
        }
    }

    if(!hasSlope() && !other.hasSlope()) {
        if(p1.x != other.p1.x){
            flag = true;
        }
    }

    return flag;
}

bool Line::isCollinear(const Line& other) const{
    bool coll = false;

    if(hasSlope() && other.hasSlope()) {
        if(slope() == other.slope() &&
           yIntercept() == other.yIntercept()) {
           coll = true;
        }
    }

    return coll;
}

bool Line::isPerpendicular(const Line& other) const{
    bool perp = false;

    if(slope() * other.slope() == -1) {
        perp = true;
    }

    return perp;
}

Point Line::intersect(const Line& other) const{
    double xInt;
    double yInt;

    xInt  = static_cast<double>(other.yIntercept() - yIntercept())
            / (slope() - other.slope());

    if(!hasSlope()) {
        xInt = p1.x;
    }
    else if (!other.hasSlope()) {
        xInt = other.p1.x;
    }

    yInt = slope() * xInt + yIntercept();

    Point Inter(xInt, yInt);

    return Inter;
}
/*
Point Line::intersect(const Line& other) const{
   double x, y;
   if(hasSlope() && other.hasSlope(1)){
        x = (other.yIntercept() - yIntercept() /
             slope() - other.slope();
   }
   else if(hasSlope()){
    x = other.getPointOne().x;
   }
   else{
    x = p1.x;
   }
   y = slope() * x + yIntercept();
   return Point(x,y);
*/

void Line::display(ostream& output) const{
    if(hasSlope()) {
        output << "y = ";
        if(slope() != 0 && abs(slope()) != 1) {
            output << slope();
        }
        else if(slope() < 0) {
            output << "-";
        }

        output << "x ";

        if(yIntercept() != 0) {
            if(yIntercept() > 0) {
                output << "+ ";
            }
            output << yIntercept();
        }
    }
    else {
        output << "x = " << p1.x;
    }
}
