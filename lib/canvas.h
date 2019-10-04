#pragma once

#include "shape.h"
#include <vector>

class Canvas
{
    public:

        Canvas() = default;
        ~Canvas();

        template<Shape::Type T,typename... A>
        void add(A...);

        void remove(const Point&);

        void show(const Point&);
        void hide(const Point&);

    private:
    
        std::vector<Shape*> _sh;

        template<Shape::Type T,typename... A>
        Shape *create(A... a)
        {
            if constexpr (T == Shape::Type::Line)
                return new ShapeLine(a...);
            else if constexpr (T == Shape::Type::Circle)
                return new ShapeCircle(a...);
            else
                return nullptr;
            
        }
};
//-----------------------------------------------------------------

template<Shape::Type T,typename... A>
void Canvas::add(A... a)
{
    Shape *p = create<T>(a...);

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
