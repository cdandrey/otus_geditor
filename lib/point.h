#pragma once

#include <iostream>

class Point
{ 
    public:

        explicit Point(int x = 0,int y = 0) :_x(x),_y(y) {}

        friend Point&        operator += (Point& lh,const Point& rh);
        friend bool          operator == (const Point& lh,const Point& rh);
        friend std::ostream& operator << (std::ostream& os, const Point& p);
        friend std::istream& operator >> (std::istream& is, Point& p);

        int x() const { return _x; }
        int y() const { return _y; }

    private:

        int _x;
        int _y;
};