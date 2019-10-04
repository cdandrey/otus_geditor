#include "shape.h"
#include <cmath>

ShapeLine::ShapeLine(const Point& begin,const Point& end) 
    : _begin{begin}
    , _end{end}
{
    if (begin.x() == end.x())
        _k = 0.0;
    else
        _k = static_cast<double>(end.y() - begin.y()) / static_cast<double>(end.x() - begin.x());

    _c = _k * begin.x() - begin.y(); 

    std::cout << "Create " << *this << std::endl;
}
//---------------------------------------------------------

ShapeLine::~ShapeLine()
{
    std::cout << "Remove " << *this << std::endl;
}
//---------------------------------------------------------

void ShapeLine::hide()
{ 
    std::cout << "Hide "  << *this << std::endl;
}
//---------------------------------------------------------

void ShapeLine::show()
{
    std::cout << "Show " << *this << std::endl;
}
//---------------------------------------------------------

void ShapeLine::move(const Point& dp)
{
    std::cout << "Move " << *this;

    _begin += dp;
    _end += dp;

    std::cout << " to: " << *this << std::endl;
}
//---------------------------------------------------------

bool ShapeLine::inhere(const Point& p)
{
    return    (p.y() == static_cast<int>(std::ceil(_k * p.x() - _c)))
           && p.y() >= _begin.y() && p.y() <= _end.y()
           && p.x() >= _begin.x() && p.x() <= _end.x();
}
//---------------------------------------------------------

std::ostream& operator << (std::ostream& os,const ShapeLine& sh)
{
    return os << "line: begin: " << sh._begin << " end: " << sh._end;
}
//***************** circle ********************************

ShapeCircle::ShapeCircle(const Point& center,int radius) 
    : _center{center}
    , _radius{radius}
{
    std::cout << "Create " << *this << std::endl;
}
//---------------------------------------------------------

ShapeCircle::~ShapeCircle()
{
    std::cout << "Remove " << *this << std::endl;
}
//---------------------------------------------------------

void ShapeCircle::hide()
{ 
    std::cout << "Hide " << *this << std::endl;
}
//---------------------------------------------------------

void ShapeCircle::show()
{
    std::cout << "Show " << *this << std::endl;
}
//---------------------------------------------------------

void ShapeCircle::move(const Point& dp)
{
    std::cout << "Move " << *this;

    _center += dp;

    std::cout << " to: " << *this << std::endl;
}
//---------------------------------------------------------

bool ShapeCircle::inhere(const Point& p)
{
    return _radius*_radius >=   (p.x() - _center.x()) * (p.x() - _center.x()) 
                              + (p.y() - _center.y()) * (p.y() - _center.y());
}
//---------------------------------------------------------

std::ostream& operator << (std::ostream& os,const ShapeCircle& sh)
{
    return os << "circle: center: " << sh._center << " radius: " << sh._radius;
}
//---------------------------------------------------------