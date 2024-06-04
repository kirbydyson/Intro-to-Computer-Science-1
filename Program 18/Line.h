#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <ostream>
#include <iostream>
#include "Point.h"

using namespace std;


class Line{
	private:
		Point p1, p2;

	public:
		Line(Point=Point(1,1), Point=Point(0,0));

 		void setFirstPoint(const Point&);
		void setSecondPoint(const Point&);

		Point getFirstPoint() const;
		Point getSecondPoint() const;

		bool   hasSlope() const;
        double slope() const;
		double yIntercept() const;

		bool isParallel(const Line&) const;
		bool isCollinear(const Line&) const;
		bool isPerpendicular(const Line&) const;

		Point intersect(const Line&) const;
		Line& operator= (const Line&);

		void display(ostream&) const;
};

#endif // LINE_H_INCLUDED
