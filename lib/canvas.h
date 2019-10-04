#pragma once

#include "shape.h"
#include <vector>
#include <tuple>

class Canvas
{
    public:

        Canvas() = default;
        ~Canvas();

        void add(Shape *);
        void remove(const Point&);

        void show(const Point&);
        void hide(const Point&);

    private:
    
        std::vector<Shape*> _sh;
};
//-----------------------------------------------------------------
