#include "point.h"

Point& operator += (Point& lh,const Point& rh)
{
    lh._x += rh._x;
    lh._y += rh._y;

    return lh;
}
//--------------------------------------------------------------

bool operator == (const Point& lh, const Point& rh)
{
    return lh.x() == rh.y() && lh.y() == rh.y();

}
//--------------------------------------------------------------

std::ostream& operator << (std::ostream& os, const Point& p)
{
    return os << "{" << p._x << "," << p._y << "}";
}
//--------------------------------------------------------------

std::istream& operator >> (std::istream& is, Point& p)
{
    is >> p._x >> p._y;

    return is;
}
//--------------------------------------------------------------
