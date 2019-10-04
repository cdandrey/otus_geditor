#pragma once

#include "shape.h"
#include <vector>
#include <tuple>

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
            std::tuple<A...> t = std::make_tuple(a...);

            if constexpr (   T == Shape::Type::Line
                          && std::is_same<std::decltype(std::get<0>(t)),Point>::value 
                          && std::is_same<std::decltype(std::get<1>(t)),Point>::value)
                return new ShapeLine(a...);
            else if constexpr (   T == Shape::Type::Circle 
                               && std::is_same<std::decltype(std::get<0>(t)),Point>::value 
                               && std::is_same<std::decltype(std::get<1>(t)),int>::value)
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
