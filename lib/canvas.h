#pragma once

#include "shape.h"
#include <vector>

class Canvas
{
    public:

        Canvas() = default;
        ~Canvas();

        template<typename... A>
        void add(const Shape::Type&,A...);

        void remove(const Point&);

        void show(const Point&);
        void hide(const Point&);

    private:
    
        std::vector<Shape*> _sh;
};
//-----------------------------------------------------------------

template<typename... A>
void Canvas::add(const Shape::Type& t,A... a)
{
    Shape *p;

    if (t == Shape::Type::Line)
        p = new ShapeLine(a...);
    else if (t == Shape::Type::Circle)
        p = new ShapeCircle(a...);
    else
        p = nullptr;

    if (p != nullptr)
    {
        _sh.push_back(p);
        _sh.at(_sh.size() - 1)->show();
    }
    else
    {
        std::cout << "Unknow type of shape" << std::endl;
    }
    
}
//-----------------------------------------------------------------
